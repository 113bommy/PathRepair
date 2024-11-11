#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}
const int N = 2e5 + 5;
const int oo = 1e9 + 7;
vector<int> divs[N];
int g[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n = N;
  cin >> n;
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) divs[j].emplace_back(i);
  }
  for (int i = 3; i < n; i++) {
    vector<int> x;
    for (int k : divs[2 * i]) {
      int xx = (i - k * (k - 1) / 2) / k;
      if (xx > 0 and xx * k + (k) * (k - 1) / 2 == i)
        x.emplace_back(g[xx + k - 1] ^ g[xx - 1]);
    }
    sort(x.begin(), x.end());
    for (int j : x) {
      if (g[i] < j)
        break;
      else if (g[i] > j)
        continue;
      else if (g[i] == j)
        g[i]++;
    }
    g[i] ^= g[i - 1];
  }
  vector<pair<int, int> > x;
  for (int k : divs[2 * n]) {
    int xx = (n - k * (k - 1) / 2) / k;
    if (xx > 0 and xx * k + (k) * (k - 1) / 2 == n)
      x.emplace_back(make_pair(g[xx + k - 1] ^ g[xx - 1], k));
  }
  sort(x.begin(), x.end());
  for (auto jj : x) {
    int j = jj.first;
    if (g[n] < j)
      break;
    else if (g[n] > j)
      continue;
    else if (g[n] == j)
      g[n]++;
  }
  if (g[n]) {
    cout << x.back().second << "\n";
  } else
    cout << "-1\n";
}
