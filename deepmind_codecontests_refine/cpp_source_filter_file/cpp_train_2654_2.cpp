#include <bits/stdc++.h>
using namespace std;
bool poss = false;
int color[100001];
vector<int> Adj[100001];
vector<pair<int, int> > v1;
int count1 = 0;
int count2 = 0;
bool visited[100001];
void DFS(int u, int p) {
  visited[u] = true;
  color[u] = (1 - color[p]);
  if (color[u] == 0) {
    count1++;
  } else {
    count2++;
  }
  for (vector<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++) {
    if (!visited[(*it)]) {
      DFS((*it), u);
    } else {
      if (color[(*it)] == color[u]) {
        poss = true;
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    Adj[a].push_back(b);
    Adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      DFS(i, i);
      v1.push_back(make_pair(count1, count2));
      count1 = 0;
      count2 = 0;
    }
  }
  if (poss) {
    printf("0 1\n");
  } else {
    long long int answer1 = 0;
    for (vector<pair<int, int> >::iterator it = v1.begin(); it != v1.end();
         it++) {
      pair<int, int> t1 = (*it);
      answer1 += ((long long int)(t1.first) * (t1.first - 1)) / 2;
      answer1 += ((long long int)(t1.second) * (t1.second - 1)) / 2;
    }
    if (m == 0) {
      answer1 = (n * (long long int)(n - 1) * (long long int)(n - 2)) / 6;
      printf("3 %lld\n", answer1);
    } else {
      if (answer1 != 0) {
        printf("1 %lld\n", answer1);
      } else {
        answer1 = ((long long int)(v1.size())) * (n - 2);
        printf("2 %lld\n", answer1);
      }
    }
  }
  return 0;
}
