#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T> read(int n) {
  vector<T> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  return v;
}
template <typename T>
void write(const vector<T>& v, const char* c = " ") {
  for (int n = v.size(), i = 0; i < n; ++i) {
    cout << v[i] << (i == n - 1 ? "\n" : c);
  }
}
void solve() {
  int n;
  cin >> n;
  auto t = read<int>(n);
  auto check = [&](int i) -> bool {
    if (i < 0 || i >= n - 1) return true;
    if (i % 2 == 0 && t[i] >= t[i + 1]) return false;
    if (i % 2 == 1 && t[i] <= t[i + 1]) return false;
    return true;
  };
  vector<int> bad;
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (!check(i)) {
      bad.push_back(i);
      j = i;
    }
  }
  if (bad.size() > 3) {
    cout << 0 << endl;
    return;
  }
  auto fix = [&](int i, int j) -> bool {
    swap(t[i], t[j]);
    bool ok = true;
    for (int k : bad) {
      if (!check(k)) ok = false;
    }
    if (!check(i - 1)) ok = false;
    if (!check(i)) ok = false;
    if (!check(j - 1)) ok = false;
    if (!check(j)) ok = false;
    swap(t[i], t[j]);
    return ok;
  };
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (fix(i, j)) ++ans;
  for (int i = 0; i < n; ++i)
    if (fix(i, j + 1)) ++ans;
  if (fix(j, j + 1)) --ans;
  cout << ans << endl;
}
void configure_ios() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
int main() {
  configure_ios();
  solve();
  return 0;
}
