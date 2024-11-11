#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
int visit[1000005];
int N;
int have[1000005];
void dfs(int n) {
  visit[n] = 1;
  for (vector<int>::iterator it = v[n].begin(); it != v[n].end(); it++) {
    if (!visit[*it]) {
      dfs(*it);
    }
  }
}
bool check() {
  for (int i = 0; i < N; i++)
    if (!visit[i] && have[i]) return false;
  return true;
}
int main() {
  int m;
  scanf("%d %d", &N, &m);
  int self = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    have[a] = 1;
    have[b] = 1;
    if (a == b)
      self++;
    else {
      v[a].push_back(b);
      v[b].push_back(a);
    }
  }
  for (int i = 0; i <= N; i++) {
    if (v[i].size() != 0) {
      dfs(i);
      break;
    }
  }
  if (check()) {
    long long ans = 0;
    for (int i = 1; i <= N; i++)
      ans += (long long)v[i].size() * (v[i].size() - 1) / 2;
    ans += (long long)self * (m - 1);
    ans -= (long long)self * (self - 1) / 2;
    printf("%I64d\n", ans);
  } else {
    printf("0\n");
  }
}
