#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, last, ans = 0, t = 0;
  cin >> n;
  vector<long long> qwer, a(n);
  map<long long, long long> mp;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i] == a[i + 1])
      t++;
    else
      mp[a[i]] = t + 1, t = 0;
  }
  for (int i = 0; i < n; i++) {
    last = -1;
    for (int j = 0; j < n; j++) {
      if (mp[a[j]] > 0 && last != a[j])
        qwer.push_back(a[j]), last = a[j], mp[a[j]]--;
    }
  }
  for (int i = 0; i < n - 1; i++)
    if (qwer[i] < qwer[i + 1]) ans++;
  cout << ans << endl;
}
