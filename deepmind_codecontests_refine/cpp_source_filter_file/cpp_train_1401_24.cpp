#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long N = 1e7 + 5;
int cnt = 0, prime[N];
bitset<N> vis;
void pre() {
  for (int i = 2; i < N; ++i) {
    if (!vis[i]) prime[cnt++] = i;
    for (int j = 0; i * prime[j] < N; ++j) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int main() {
  int n, m;
  cin >> n;
  if (n == 2) {
    cout << "1 1" << endl;
    return 0;
  }
  if (n == 3) {
    cout << "1 1 2" << endl;
    return 0;
  }
  if (n == 4) {
    cout << "1 1 2 1" << endl;
    return 0;
  }
  if (n == 5) {
    cout << "1 2 1 1 1" << endl;
    return 0;
  }
  if (n == 6) {
    cout << "1 2 1 1 1 1" << endl;
    return 0;
  }
  pre();
  m = n * (n + 1) / 2;
  bool sign = 0;
  vector<int> res(n + 1, 0);
  int flag = 0;
  if (m & 1) {
    if (!vis[m - 2]) {
      ++res[2];
      res.erase(res.begin());
      for (auto i : res) cout << i + 1 << " ";
      cout << endl;
      return 0;
    }
    m -= 3;
    flag = 3;
    res[3] = 2;
  }
  for (auto i : prime) {
    int t = m - i;
    if (!i || t < 0) break;
    if (!vis[t]) {
      for (int i = n; t && i > flag; --i) {
        if (i == flag) continue;
        if (i <= t) {
          t -= i;
          ++res[i];
        }
      }
      if (t) {
        res = vector<int>(n + 1, 0);
        res[flag] = 2;
      } else {
        sign = 1;
        break;
      }
    }
  }
  if (!sign) {
    cout << -1 << endl;
    return 0;
  }
  res.erase(res.begin());
  for (auto i : res) cout << i + 1 << " ";
  cout << endl;
}
