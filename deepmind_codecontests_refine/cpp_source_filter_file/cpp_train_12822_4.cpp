#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
int n, m, k;
int f(int& i, long long d, long long p) {
  int ret = 0;
  while (i < a.size() && a[i] - d <= p * k) {
    ++ret;
    ++i;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  a.resize(m);
  for (auto& i : a) cin >> i;
  sort(a.begin(), a.end());
  long long d = 0, p = 1, ret = 0;
  for (int i = 0; i < m;) {
    int t;
    while ((t = f(i, d, p))) {
      d += t;
      ++ret;
    }
    if (i < m) {
      p = (a[i] - d - 1) / k + 1;
    }
  }
  cout << ret;
  return 0;
}
