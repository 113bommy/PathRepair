#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int minn(int a, int b) {
  if (a < b) return a;
  return b;
}
int maxx(int a, int b) {
  if (a > b) return a;
  return b;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    long long int n, i, anslast = 0, ans, x = 0, y = 0, len;
    string s;
    cin >> n >> s;
    map<pair<long long int, long long int>, long long int> mapp;
    mapp.clear();
    mapp[make_pair(0ll, 0ll)] = -1;
    ans = n + 1;
    bool got = 0;
    for (i = 0; i < n; i++) {
      char a = s[i];
      if (a == 'L')
        x--;
      else if (a == 'R')
        x++;
      else if (a == 'U')
        y++;
      else if (a == 'D')
        y--;
      pair<long long int, long long int> p = make_pair(x, y);
      if (mapp.find(p) != mapp.end()) {
        len = i - mapp[p];
        if (len < ans) {
          ans = len;
          anslast = i;
          got = 1;
        }
      }
      mapp[p] = i;
    }
    anslast++;
    if (got)
      cout << anslast - ans + 1 << ' ' << anslast << endl;
    else
      cout << "-1\n";
  }
}
