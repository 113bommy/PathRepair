#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> d(5001);
  vector<int> r;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (d[a[j] - a[i]] == 0) r.push_back(a[j] - a[i]);
      d[a[j] - a[i]]++;
    }
  vector<int> suf(5001);
  for (int i = 5000; i >= 0; i--) {
    if (i == 5000)
      suf[i] = d[i];
    else
      suf[i] = suf[i + 1] + d[i];
  }
  long long ans = 0;
  for (int i = 0; i < (int)r.size(); i++) {
    for (int j = 0; j < (int)r.size(); j++) {
      if (r[i] + r[j] < 5000) {
        ans += d[r[i]] * 1ll * d[r[j]] * 1ll * suf[r[i] + r[j] + 1];
      }
    }
  }
  cout.precision(30);
  cout << double(ans) /
              double((n * (n - 1) / 2) * (n * (n - 1) / 2) * (n * (n - 1) / 2));
}
