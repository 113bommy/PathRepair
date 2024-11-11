#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, vector<int> > &a, pair<long long, vector<int> > &b) {
  if (a.first != b.first) return a.first < b.first;
  for (int i = 0; i < a.second.size(); ++i)
    if (a.second[i] != b.second[i]) return a.second[i] > b.second[i];
}
long long calc(vector<int> &v) {
  int n = v.size();
  long long res = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int mi = n;
      for (int k = i; k <= j; ++k) mi = min(mi, v[k]);
      res += mi;
    }
  return res;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  k--;
  vector<int> res(n);
  long long a = (1ll << n - 2);
  int st = 0, ed = n - 1;
  int step = 1;
  while (a != 0) {
    if (k < a) {
      res[st] = step;
      st++;
    } else {
      res[ed] = step;
      ed--;
      k -= a;
    }
    step++;
    a /= 2;
  }
  res[st] = step;
  for (int i = 0; i < n; ++i) cout << res[i] << " ";
  cout << endl;
}
int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  solve();
}
