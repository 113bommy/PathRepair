#include <bits/stdc++.h>
using namespace std;
bool isp(int long long n) {
  if (n == 1) return false;
  for (int long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int long long n, t, q, k, st, maxi, mini, cnt, a, b, c, d, e, f, m, len, x, y,
      z, w, ans = 0, no;
  string str;
  bool flag = true;
  t = 1;
  while (t--) {
    cin >> n;
    int long long arr[n];
    unordered_map<int long long, int long long> mp;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      mp[arr[i]]++;
    }
    sort(arr, arr + n);
    cnt = arr[n - 1] - arr[0];
    for (auto it = mp.begin(); it != mp.end(); it++) {
      if (mp.find(it->first + cnt) != mp.end()) {
        if (cnt != 0)
          ans += mp[it->first] * mp[it->first + cnt];
        else
          ans += mp[it->first] * (mp[it->first + cnt] - 1);
      }
    }
    cout << cnt << " " << ans << endl;
  }
}
