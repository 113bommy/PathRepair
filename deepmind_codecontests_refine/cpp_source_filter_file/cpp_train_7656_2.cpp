#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  set<long long> r;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    r.insert(a[i]);
  }
  sort(a.begin(), a.end());
  if (r.size() == 1 || r.size() == 2) {
    cout << "YES";
    return 0;
  }
  if (r.size() > 3) {
    cout << "NO";
    return 0;
  }
  vector<long long> r0;
  for (auto c : r) r0.push_back(c);
  r.clear();
  long long mmin = r0[0];
  long long mmax = r0[r0.size() - 1];
  long long sr = r0[r0.size() / 2];
  if ((mmin + mmax + 1) / 2 == sr)
    cout << "YES";
  else
    cout << "NO";
}
