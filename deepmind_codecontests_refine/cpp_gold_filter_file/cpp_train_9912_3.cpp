#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, s;
  cin >> n >> s;
  long long int a[n];
  long long int sum = 0;
  vector<long long int> pref;
  pref.push_back(0);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    pref.push_back(pref.back() + a[i]);
  }
  pref.push_back(1000000000000000000);
  auto lastIt = lower_bound(pref.begin(), pref.end(), s);
  if ((*lastIt) > s) {
    lastIt--;
  }
  long long int last = lastIt - pref.begin();
  long long int maxm = last;
  long long int part = 0;
  if (sum <= s) {
    cout << 0 << "\n";
    return;
  }
  for (long long int i = 1; i <= last + 1; i++) {
    long long int ans = 0;
    ans += (i - 1);
    long long int temp = s - pref[i - 1];
    long long int key = (temp + pref[i]);
    auto it = lower_bound(pref.begin() + i + 1, pref.end(), key);
    if (*it > key) {
      it--;
    }
    long long int cnt = (it - (pref.begin() + i));
    ans += cnt;
    if (maxm < ans) {
      part = i;
      maxm = max(maxm, ans);
    }
  }
  cout << part << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
