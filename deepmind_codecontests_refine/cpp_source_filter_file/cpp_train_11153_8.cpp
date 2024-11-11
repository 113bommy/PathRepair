#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  string robin;
  robin = s;
  if (n < 3) {
    long long r = 0, g = 0, b = 0;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'R') {
        r++;
      }
      if (s[i] == 'G') g++;
      if (s[i] == 'B') b++;
    }
    if (r == 2) {
      cout << 1 << '\n';
      cout << "RG" << '\n';
    }
    if (g == 2) {
      cout << 1 << '\n';
      cout << "GR" << '\n';
    }
    if (b == 2) {
      cout << 1 << '\n';
      cout << "BG" << '\n';
    } else {
      cout << 0 << '\n';
      cout << s << '\n';
    }
  } else {
    s = robin;
    map<long long, string> mp;
    long long mn = 100000;
    string tempo = s;
    for (long long i = 0; i < 6; ++i) {
      long long cnt = 0;
      s = tempo;
      if (i == 0) {
        if (s[0] != 'R') {
          cnt++;
        }
        s[0] = 'R';
        if (s[1] != 'G') {
          cnt++;
        }
        s[1] = 'G';
        if (s[2] != 'B') {
          cnt++;
        }
        s[2] = 'B';
      }
      if (i == 1) {
        if (s[0] != 'R') {
          cnt++;
        }
        s[0] = 'R';
        if (s[1] != 'B') {
          cnt++;
        }
        s[1] = 'B';
        if (s[2] != 'G') {
          cnt++;
        }
        s[2] = 'G';
      }
      if (i == 2) {
        if (s[0] != 'G') {
          cnt++;
        }
        s[0] = 'G';
        if (s[1] != 'B') {
          cnt++;
        }
        s[1] = 'B';
        if (s[2] != 'R') {
          cnt++;
        }
        s[2] = 'R';
      }
      if (i == 3) {
        if (s[0] != 'G') {
          cnt++;
        }
        s[0] = 'G';
        if (s[1] != 'R') {
          cnt++;
        }
        s[1] = 'R';
        if (s[2] != 'B') {
          cnt++;
        }
        s[2] = 'B';
      }
      if (i == 4) {
        if (s[0] != 'B') {
          cnt++;
        }
        s[0] = 'B';
        if (s[1] != 'G') {
          cnt++;
        }
        s[1] = 'G';
        if (s[2] != 'R') {
          cnt++;
        }
        s[2] = 'R';
      }
      if (i == 5) {
        if (s[0] != 'B') {
          cnt++;
        }
        s[0] = 'B';
        if (s[1] != 'R') {
          cnt++;
        }
        s[1] = 'R';
        if (s[2] != 'G') {
          cnt++;
        }
        s[2] = 'G';
      }
      if (n > 3) {
        for (long long j = 3; j < n; j++) {
          if (s[j] != s[j % 3]) {
            cnt++;
            s[j] = s[j % 3];
          }
        }
      }
      mp[cnt] = s;
      mn = min(mn, cnt);
    }
    cout << mn << '\n';
    cout << mp[mn] << '\n';
  }
  return 0;
}
