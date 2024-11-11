#include <bits/stdc++.h>
using namespace std;
const long long N = 200 * 1000 + 9;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
void HakunaMatata() {
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> a, b;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    if (y == 1)
      a.emplace_back(x, i + 1);
    else
      b.emplace_back(x, i + 1);
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  double ans = 0.0;
  vector<long long> idx(k);
  vector<long long> kk;
  if ((long long)a.size() < k) {
    for (long long i = 0; i < (long long)a.size(); i++) {
      ans = ans + (1.0 * a[i].first) / 2;
      idx[i] = a[i].second;
    }
    long long j = 0;
    for (long long i = (long long)a.size(); i < k - 1; i++) {
      ans = ans + b[j].first;
      idx[i] = b[j].second;
      j++;
    }
    while (j < (long long)b.size()) {
      ans = ans + b[j].first;
      kk.push_back(b[j].second);
      j++;
    }
    cout << setprecision(1) << fixed << ans << '\n';
    for (long long i = 0; i < k - 1; i++) {
      cout << 1 << " " << idx[i] << '\n';
    }
    cout << (long long)kk.size() << " ";
    for (long long i = 0; i < (long long)kk.size(); i++) {
      cout << kk[i] << " ";
    }
    cout << '\n';
  } else if ((long long)a.size() == k) {
    for (long long i = 0; i < (long long)a.size() - 1; i++) {
      ans = ans + (1.0 * a[i].first) / 2;
      idx[i] = a[i].second;
    }
    long long j = 0;
    vector<long long> temp;
    kk.push_back(a[k - 1].second);
    temp.push_back(a[k - 1].first);
    ans = ans + a[k - 1].first;
    while (j < (long long)b.size()) {
      ans = ans + b[j].first;
      kk.push_back(b[j].second);
      temp.push_back(b[j].first);
      j++;
    }
    if (temp.size() > 0) {
      sort(temp.begin(), temp.end());
      ans = ans - temp[0];
      ans = ans + (1.0 * temp[0]) / 2;
    }
    cout << setprecision(1) << fixed << ans << '\n';
    for (long long i = 0; i < k - 1; i++) {
      cout << 1 << " " << idx[i] << '\n';
    }
    cout << (long long)kk.size() << " ";
    for (long long i = 0; i < (long long)kk.size(); i++) cout << kk[i] << " ";
    cout << '\n';
  } else {
    for (long long i = 0; i < k - 1; i++) {
      ans = ans + (1.0 * a[i].first) / 2;
      idx[i] = a[i].second;
    }
    long long i = k - 1;
    vector<long long> temp;
    while (i < (long long)a.size()) {
      ans = ans + a[i].first;
      kk.push_back(a[i].second);
      temp.push_back(a[i].first);
      i++;
    }
    long long j = 0;
    while (j < (long long)b.size()) {
      ans = ans + b[j].first;
      kk.push_back(b[j].second);
      temp.push_back(b[j].first);
      j++;
    }
    if ((long long)temp.size() > 0) {
      sort(temp.begin(), temp.end());
      ans = ans - temp[0];
      ans = ans + (1.0 * temp[0]) / 2;
    }
    cout << setprecision(1) << fixed << ans << '\n';
    for (long long i = 0; i < k - 1; i++) {
      cout << 1 << " " << idx[i] << '\n';
    }
    cout << (long long)kk.size() << " ";
    for (long long i = 0; i < (long long)kk.size(); i++) {
      cout << kk[i] << " ";
    }
    cout << '\n';
  }
  return;
}
signed main() {
  HakunaMatata();
  return 0;
}
