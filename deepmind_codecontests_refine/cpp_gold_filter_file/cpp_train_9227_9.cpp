#include <bits/stdc++.h>
using namespace std;
long long Pow(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = Pow(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
bool run(long long n, long long x1, long long x2, long long mx, long long mn,
         vector<pair<long long, long long> > a) {
  vector<long long> ans[2];
  long long index1 = -1, index2 = -1, i, j;
  for (i = 1; i <= n - 1; i++) {
    long long x = ceil((long double)(mx + 0.0) / (i + 0.0));
    if (x <= a[i - 1].first) {
      index1 = i;
      break;
    }
  }
  if (index1 == -1) return false;
  for (i = index1 + 1; i <= n; i++) {
    long long x = ceil((long double)(mn + 0.0) / (i - index1 + 0.0));
    if (x <= a[i - 1].first) {
      index2 = i;
      break;
    }
  }
  if (index2 == -1) return false;
  cout << "Yes"
       << "\n";
  j = 0;
  if (x2 == mx) j = 1;
  for (long long k = 0; k < index1; k++) ans[j].push_back(a[k].second + 1);
  j = 1 - j;
  for (long long k = index1; k < index2; k++) ans[j].push_back(a[k].second + 1);
  cout << ans[0].size() << " " << ans[1].size() << "\n";
  for (i = 0; i < 2; i++) {
    for (auto x : ans[i]) cout << x << " ";
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j;
  long long n, x1, x2;
  cin >> n >> x1 >> x2;
  long long mx = max(x1, x2);
  long long mn = min(x2, x1);
  vector<pair<long long, long long> > a;
  for (i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back({x, i});
  }
  sort(a.begin(), a.end(), greater<pair<long long, long long> >());
  bool x = run(n, x1, x2, x1, x2, a) || run(n, x1, x2, x2, x1, a);
  if (x == false)
    cout << "No"
         << "\n";
}
