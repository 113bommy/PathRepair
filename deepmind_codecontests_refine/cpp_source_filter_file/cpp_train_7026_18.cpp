#include <bits/stdc++.h>
using namespace std;
;
int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
int main(void) {
  int n, m;
  scanf("%d %d\n", &n, &m);
  vector<int> adj_list[n];
  int arr[m][2];
  int degree[n];
  int min_ans = 10000000;
  for (int i = 0; i < m; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    s--;
    e--;
    adj_list[s].push_back(e);
    adj_list[e].push_back(s);
    arr[i][0] = s;
    arr[i][1] = e;
  }
  for (int i = 0; i < n; i++) {
    degree[i] = adj_list[i].size();
  }
  for (int i = 0; i < m; i++) {
    int s = arr[i][0];
    int e = arr[i][1];
    for (int j = 0; j < adj_list[s].size(); j++) {
      int holder = adj_list[s][j];
      for (int k = 0; k < adj_list[e].size(); k++) {
        if (holder == adj_list[e][k]) {
          int tempo = degree[s] + degree[e] + degree[holder] - 6;
          if (tempo < min_ans) {
            min_ans = tempo;
          }
        }
      }
    }
  }
  if (min_ans = 10000000) {
    min_ans = -1;
  }
  printf("%d\n", min_ans);
}
