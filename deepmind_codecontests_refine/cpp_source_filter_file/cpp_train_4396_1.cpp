#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> fac[N + 5];
int miu[N];
bool vis[N];
inline void init() {
  miu[1] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = i + i; j <= N; j += i) {
      fac[j].push_back(i);
      miu[j] -= miu[i];
      vis[i] |= vis[j];
    }
    fac[i].push_back(i);
  }
}
int cnt[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vis[x] = 1;
  }
  init();
  auto update = [](int x, int a) {
    for (auto t : fac[x]) {
      cnt[t] += a;
    }
  };
  auto is = [](int x) {
    int res = 0;
    for (auto t : fac[x]) {
      res += miu[t] * cnt[t];
    }
    return res;
  };
  stack<int> s;
  for (int i = N; i >= 2; i--) {
    if (!vis[i]) continue;
    if (i > ans) ans = i;
    while (is(i)) {
      ans = max(ans, 1ll * i * s.top());
      update(s.top(), -1);
      s.pop();
    }
    update(i, 1);
    s.push(i);
  }
  cout << ans;
}
