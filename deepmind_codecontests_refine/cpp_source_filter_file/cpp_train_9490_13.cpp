#include <bits/stdc++.h>
using namespace std;
int n, m, mon;
int a, b;
vector<int> A;
vector<pair<int, int>> B(200005);
int dir;
bool solve(int x) {
  vector<int> L(n, -1);
  for (int i = 0; i < m; i++) {
    if (B[i].first <= x) {
      L[B[i].second] = max(B[i].first, L[B[i].second]);
    }
  }
  vector<vector<int>> off(200005);
  for (int i = 0; i < n; i++) {
    if (L[i] != -1) {
      off[L[i]].push_back(i);
    }
  }
  vector<int> t = A;
  mon = 0;
  for (int u = 0; u <= x; u++) {
    mon++;
    if (u > 200000) {
      mon = mon + u - 200001;
      break;
    }
    for (auto it : off[u]) {
      if (mon >= t[it]) {
        mon = mon - t[it];
        t[it] = 0;
      } else {
        t[it] = t[it] - mon;
        mon = 0;
      }
    }
  }
  return accumulate(t.begin(), t.end(), 0) * 2 <= mon;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    A.push_back(a);
    dir = dir + A[i];
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    B[i].first = a - 1;
    B[i].second = b - 1;
  }
  int l = 0, r = dir * 2, mid;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (solve(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (solve(l)) {
    cout << l + 1 << endl;
  } else {
    cout << r + 1 << endl;
  }
}
