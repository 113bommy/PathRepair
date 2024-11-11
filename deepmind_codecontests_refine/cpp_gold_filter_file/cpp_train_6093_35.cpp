#include <bits/stdc++.h>
using namespace std;
const int INF = 2 * int(1e9);
const long long INFll = 1ll * INF * INF;
const int MOD = 1000000007;
template <class T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <class T>
ostream& operator<<(ostream& out, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<pair<T, T> >& a) {
  for (int i = 0; i < a.size(); ++i)
    out << a[i].first << " " << a[i].second << endl;
  return out;
}
template <class T>
istream& operator>>(istream& in, vector<pair<T, T> >& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i].first >> a[i].second;
  return in;
}
long long convert(vector<int>& x) {
  long long res = 0;
  long long cur = 1;
  for (int i = 0; i < x.size(); ++i) res += x[i] * cur, cur *= 2;
  return res;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  n++;
  vector<int> a(n);
  cin >> a;
  vector<int> res(n);
  for (int i = 0; i < n; ++i) res[i] = a[i];
  bool negative = 0;
  for (int i = 0; i < res.size(); ++i) {
    if (res[i] >= 0 && res[i] <= 1) continue;
    if (i == res.size() - 1) {
      if (res[i] == -1) {
        negative = 1;
        res[i] *= -1;
        for (int j = 0; j < i; ++j) res[j] *= -1;
        break;
      }
      res.push_back(0);
    }
    if (res[i] < 0)
      res[i + 1] -= abs(res[i]) / 2 + abs(res[i]) % 2, res[i] = abs(res[i]) % 2;
    else
      res[i + 1] += res[i] / 2, res[i] %= 2;
  }
  if (negative)
    for (int i = 0; i < res.size(); ++i) {
      if (res[i] >= 0 && res[i] <= 1) continue;
      if (res[i] < 0)
        res[i + 1] -= abs(res[i]) / 2 + abs(res[i]) % 2,
            res[i] = abs(res[i]) % 2;
      else
        res[i + 1] += res[i] / 2, res[i] %= 2;
    }
  while (res.back() == 0) res.pop_back();
  if (0) cerr << negative << endl;
  if (0) cerr << res << endl;
  int fst = 0;
  reverse(res.begin(), res.end());
  while (res.back() == 0 && res.size() > 40) res.pop_back(), fst++;
  if (res.size() > 40) {
    cout << 0;
    return 0;
  }
  reverse(res.begin(), res.end());
  int ans = 0;
  while (fst < n) {
    long long x = convert(res);
    if (negative) x *= -1;
    if (abs(x - a[fst]) <= k && (fst < n - 1 || x - a[fst])) ans++;
    if (res[0]) break;
    res.erase(res.begin());
    fst++;
  }
  cout << ans;
  if (0)
    cerr << fixed << setprecision(0)
         << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << "\n";
  return 0;
}
