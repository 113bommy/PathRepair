#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    long long n;
    cin >> n;
    cin >> s;
    long long ans = 1;
    string anss = s;
    for (long long i = 2; i < n; i++) {
      string news;
      if ((n - i) % 2 == 0) {
        string a = s.substr(0, i - 1);
        reverse(a.begin(), a.end());
        news = s.substr(i - 1, n - i + 1) + a;
      } else
        news = s.substr(i - 1, n - i + 1) + s.substr(0, i - 1);
      if (news < s && !(news >= anss)) {
        ans = i;
        anss = news;
      }
    }
    string lat = s;
    for (long long i = 0; i < n; i++) {
      lat[i] = s[n - i - 1];
    }
    if (lat < anss) {
      anss = lat;
      ans = n;
    }
    cout << anss << endl << ans << endl;
  }
  return 0;
}
