#include <bits/stdc++.h>
using namespace std;
char s[1000000];
int parent[200000], num = 0;
char type[200000];
vector<int> adjList[200000];
int dp[200000];
int findSol(int u, int no, int r) {
  if (type[u] == '*') {
    if (!no)
      printf(" %I64d", (long long int)dp[0] * r);
    else
      printf(" 0");
    return 0;
  }
  int i;
  if (no) {
    for (i = 0; i < adjList[u].size(); i++) findSol(adjList[u][i], 1, r);
  } else {
    if (type[u] == 'S') {
      for (i = 0; i < adjList[u].size(); i++) {
        if (dp[adjList[u][i]] == dp[u]) break;
      }
      int p = i;
      for (i = 0; i < adjList[u].size(); i++) {
        if (i == p)
          findSol(adjList[u][i], 0, r);
        else
          findSol(adjList[u][i], 1, r);
      }
    } else {
      for (i = 0; i < adjList[u].size(); i++) findSol(adjList[u][i], 0, r);
    }
  }
  return 0;
}
int main() {
  int i, j;
  int t, r;
  scanf("%d", &t);
  while (t--) {
    scanf("%d ", &r);
    fgets(s, sizeof(s), stdin);
    int u = 0;
    type[u] = '*';
    for (i = 0; s[i] != '\0'; i++) {
      if (s[i] == '(') {
        adjList[u].push_back(++num), parent[num] = u;
        u = num, type[u] = '*';
      } else if ((s[i] == 'P') || (s[i] == 'S')) {
        u = parent[u], type[u] = s[i];
        adjList[u].push_back(++num), parent[num] = u;
        u = num, type[u] = '*';
      } else if (s[i] == ')')
        u = parent[u];
    }
    for (i = num; i >= 0; i--) {
      if (type[i] == 'S') {
        dp[i] = 1e9;
        for (j = 0; j < adjList[i].size(); j++)
          dp[i] = min(dp[i], dp[adjList[i][j]]);
      } else if (type[i] == 'P') {
        dp[i] = 0;
        for (j = 0; j < adjList[i].size(); j++) dp[i] += dp[adjList[i][j]];
      } else
        dp[i] = 1;
    }
    printf("REVOLTING");
    findSol(0, 0, r);
    printf("\n");
    for (i = 0; i <= num; i++) adjList[i].clear();
    num = 0;
  }
  return 0;
}
