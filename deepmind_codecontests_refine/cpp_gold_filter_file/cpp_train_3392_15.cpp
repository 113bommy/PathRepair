#include <bits/stdc++.h>
using namespace std;
const int INF = 2 * int(1e9);
const long long INFll = 1ll * int(1e9) * int(1e9);
const int MOD = 1000000007;
template <typename T, typename Q>
ostream& operator<<(ostream& out, pair<T, Q>& a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename Q>
istream& operator>>(istream& in, pair<T, Q>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
  return out;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  vector<int> k(60);
  vector<long long> b;
  for (int i = 0; i < n; ++i) {
    long long cur = 1;
    int tmp = 0;
    while (cur < a[i]) cur *= 2, tmp++;
    if (cur == a[i])
      k[tmp]++;
    else
      b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  int ans = INF;
  int l = 1, r = k[0];
  vector<long long> need;
  while (l <= r) {
    int mid = (l + r) / 2;
    vector<int> left(60);
    int j = 0;
    int cur = mid;
    long long tmp = 1;
    need.clear();
    for (int i = 0; i < 60; ++i) {
      left[i] = cur - min(cur, k[i]);
      cur = min(cur, k[i]);
      while (j < b.size() && b[j] <= tmp) need.push_back(b[j++]);
      for (int z = 0; z < k[i] - cur; ++z) need.push_back(tmp);
      tmp *= 2;
    }
    tmp /= 2;
    reverse(need.begin(), need.end());
    j = 0;
    bool good = 1;
    for (int i = 59; i >= 0; --i) {
      if (j == need.size()) break;
      if (need[j] > tmp) {
        good = 0;
        break;
      }
      while (j < need.size() && left[i]) {
        j++;
        left[i]--;
      }
      tmp /= 2;
    }
    if (j < need.size()) good = 0;
    if (!good)
      l = mid + 1;
    else {
      ans = mid;
      r = mid - 1;
    }
  }
  if (ans == INF)
    cout << "-1\n";
  else {
    for (int i = ans; i <= k[0]; ++i) cout << i << " ";
    cout << endl;
  }
  if (0)
    cerr << fixed << setprecision(0)
         << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << "\n";
  return 0;
}
