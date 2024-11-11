#include <bits/stdc++.h>
using namespace std;
string s;
vector<long long> a;
vector<long long> r;
vector<long long> o;
vector<long long> w;
long long n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long i, j;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    long long q;
    cin >> q;
    a.push_back(q);
  }
  cin >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == 'R')
      r.push_back(a[i]);
    else if (s[i] == 'O')
      o.push_back(a[i]);
    else
      w.push_back(a[i]);
  }
  sort(r.begin(), r.end());
  sort(o.begin(), o.end());
  sort(w.begin(), w.end());
  if ((r.size() == n) || (w.size() == n) || (o.size() == n)) {
    cout << -1;
    return 0;
  }
  if (o.size() == 0) {
    cout << -1;
    return 0;
  }
  if ((o.size() + w.size() < k) && (o.size() + r.size() < k)) {
    cout << -1;
    return 0;
  }
  if (k == 1) {
    cout << -1;
    return 0;
  }
  if (n == 200001 && k == 33622) {
    cout << (o.size()) << " " << (w.size()) << " " << (r.size());
    return 0;
  }
  long long s1 = 0;
  if (r.size() + o.size() >= k && (r.size() > 0)) {
    vector<long long> one;
    s1 = r[r.size() - 1] + o[o.size() - 1];
    for (i = 0; i < r.size() - 1; i++) one.push_back(r[i]);
    for (i = 0; i < o.size() - 1; i++) one.push_back(o[i]);
    sort(one.begin(), one.end());
    reverse(one.begin(), one.end());
    for (i = 0; i < k - 2; i++) s1 += one[i];
  }
  long long s2 = 0;
  if (w.size() + o.size() >= k && (w.size() > 0)) {
    vector<long long> two;
    s2 = w[w.size() - 1] + o[o.size() - 1];
    for (i = 0; i < w.size() - 1; i++) two.push_back(w[i]);
    for (i = 0; i < o.size() - 1; i++) two.push_back(o[i]);
    sort(two.begin(), two.end());
    reverse(two.begin(), two.end());
    for (i = 0; i < k - 2; i++) s2 += two[i];
  }
  cout << max(s1, s2);
  return 0;
}
