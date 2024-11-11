#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  string str = "", ss = "", s1 = "";
  char ch;
  set<long long> st, stt;
  unordered_map<char, long long> mp, mpp;
  long long d, ct = 0, q = 0, l, n = 0, k = 0, m = 0, i, x = 0, mn = 0, y = 0,
               z = 0, j = 0, s = 0, r = 0;
  long long arr[200003] = {0}, b[200003], c[200003];
  long long a[200003];
  double dr;
  cin >> t;
  while (t--) {
    mp.clear();
    s = k = d = r = l = j = m = q = x = y = z = mn = 0;
    str = "", ss = "";
    cin >> n >> k;
    cin >> str;
    for (i = 0; i < k / 2; i++) {
      x = 0;
      mp.clear();
      for (j = i; j < n; j += k) {
        mp[str[j]]++;
        x = max(mp[str[j]], x);
      }
      if (k % 2 && i == k / 2) {
        s += n / k - x;
        continue;
      }
      for (j = k - i - 1; j < n; j += k) {
        mp[str[j]]++;
        x = max(mp[str[j]], x);
      }
      s += 2 * n / k - x;
    }
    cout << s << "\n";
  }
  return 0;
}
