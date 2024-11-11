#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, m;
int a[N][10];
vector<int> sub[1 << 10];
vector<int> par[1 << 10];
bool f[1 << 10];
int b[N];
bool isSubSet(int first, int second) {
  bool flag = 1;
  for (int i = 0; i < 8; i++) {
    if (((second >> i) & 1)) {
      if (((first >> i) & 1) == 0) flag = 0;
    }
  }
  return flag;
}
bool check(int k) {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    int foo = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] >= k) {
        foo += (1 << j);
      }
    }
    f[((1 << m) - 1) ^ foo] = 1;
    b[i] = foo;
  }
  for (int i = 0; i < (1 << m); i++) {
    for (auto u : sub[i]) {
      f[i] |= f[u];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[b[i]] == 1) return 1;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < (1 << 8); i++) {
    for (int j = 0; j < i; j++) {
      if (isSubSet(i, j)) {
        sub[i].push_back(j);
        par[j].push_back(i);
      }
    }
  }
  int l = 0, r = 1000000000;
  int ans = 0;
  while (r >= l) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  int ans1, ans2;
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    int foo = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] >= ans) {
        foo += (1 << j);
      }
    }
    f[((1 << m) - 1) ^ foo] = 1;
    b[i] = foo;
  }
  for (int i = 0; i < (1 << m); i++) {
    for (auto u : sub[i]) {
      f[i] |= f[u];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[b[i]] == 1) {
      ans1 = i;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((b[i] | b[ans1]) == ((1 << m) - 1)) {
      ans2 = i;
      break;
    }
  }
  cout << ans1 << ' ' << ans2;
  return 0;
}
