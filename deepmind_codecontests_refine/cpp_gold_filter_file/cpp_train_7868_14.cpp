#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long SZ = 107;
const long long N = 1e6 + 7;
const long long M = 1e4 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  long long s = 0;
  long long halfsum = 0;
  vector<int> a(n + 5, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s & 1) {
    cout << "NO";
    return 0;
  }
  map<long long, int> mp1, mp2;
  mp1[a[0]] = 1;
  for (int i = 1; i < n; i++) {
    mp2[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    halfsum += a[i];
    if (halfsum == s / 2) {
      cout << "YES";
      return 0;
    }
    if (halfsum < s / 2) {
      long long y = (s / 2) - halfsum;
      if (mp2[y] > 0) {
        cout << "YES";
        return 0;
      }
    } else {
      long long y = halfsum - s / 2;
      if (mp1[y] > 0) {
        cout << "YES";
        return 0;
      }
    }
    mp1[a[i + 1]]++;
    mp2[a[i + 1]]--;
  }
  cout << "NO";
  return 0;
}
