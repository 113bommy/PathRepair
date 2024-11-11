#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int used[100005];
int color[100005];
int odd_cycle;
vector<pair<int, int> > v;
int odd;
int even;
void DFS(int node, int cor, int par = -1) {
  if (cor == 0) {
    even++;
  } else {
    odd++;
  }
  color[node] = cor;
  used[node] = 1;
  for (int i = 0; i < (int)g[node].size(); i++) {
    int viz = g[node][i];
    if (viz != par) {
      if (used[viz]) {
        if (cor == color[viz]) {
          odd_cycle = 1;
        }
      } else {
        DFS(viz, 1 - cor, node);
      }
    }
  }
  return;
}
int main(void) {
  int n, m;
  int a, b;
  scanf(" %d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    used[i] = 0;
    color[i] = 2;
  }
  for (int i = 0; i < m; i++) {
    scanf(" %d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  odd_cycle = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      odd = even = 0;
      DFS(i, 0);
      v.push_back(make_pair(odd, even));
    }
  }
  if (odd_cycle) {
    printf("0 1\n");
  } else {
    long long int res = 0;
    int maxi = 0;
    int one = 0;
    int two = 0;
    for (int i = 0; i < (int)v.size(); i++) {
      odd = v[i].first;
      even = v[i].second;
      if (odd + even == 1) {
        one++;
      } else if (odd + even == 2) {
        two++;
      }
      maxi = max(maxi, odd + even);
      res += (1LL * odd * (odd - 1)) / 2;
      res += (1LL * even * (even - 1)) / 2;
    }
    if (maxi >= 3) {
      printf("1 %lld\n", res);
    } else if (maxi == 2) {
      res = 1LL * two * one + 2LL * two * (two - 1);
      printf("2 %lld\n", res);
    } else {
      res = (1LL * one * (one - 1) * (one - 2)) / 6;
      printf("3 %lld\n", res);
    }
  }
  return 0;
}
