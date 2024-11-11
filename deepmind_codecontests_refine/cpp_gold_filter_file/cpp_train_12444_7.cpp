#include <bits/stdc++.h>
using namespace std;
long long powr(long long a, long long b) {
  long long c = 1;
  long long i;
  for (i = 0; i < b; i++) c *= a;
  return c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  vector<long long> vp;
  vector<long long> vn;
  getline(cin, s);
  long long n = s.size();
  long long i;
  long long p = 1;
  long long neg = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '+') p++;
    if (s[i] == '-') neg++;
  }
  long long x = 0;
  long long num = 0;
  long long poin = n - 1;
  while (s[poin] != ' ') {
    num += (powr(10, x) * (s[poin] - 48));
    x++;
    poin--;
  }
  if ((p * num - neg) < num)
    cout << "Impossible";
  else {
    if ((p - num * neg) > num)
      cout << "Impossible";
    else {
      n = num;
      cout << "Possible"
           << "\n";
      for (i = 0; i < p; i++) vp.push_back(n);
      for (i = 0; i < neg; i++) vn.push_back(1);
      long long x = p * n - neg;
      if (p - neg <= n) {
        poin = 0;
        while (1) {
          if (x == n)
            break;
          else {
            vp[poin] = 1;
            x -= (n - 1);
            if (x < n) {
              vp[poin] += (n - x);
              x = n;
            }
            poin++;
          }
        }
      } else {
        for (i = 0; i < p; i++) vp[i] = 1;
        poin = 0;
        x = p - neg;
        while (1) {
          if (x == n)
            break;
          else {
            vn[poin] = n;
            x -= (n - 1);
            if (x < n) {
              vn[poin] -= (n - x);
              x = n;
            }
            poin++;
          }
        }
      }
      cout << vp[0];
      long long pospoin = 1;
      long long negpoin = 0;
      for (i = 1; i < s.size(); i++) {
        if ((s[i] == ' ') || (s[i] == '+') || (s[i] == '-'))
          cout << s[i];
        else if ((s[i] == '?') && (s[i - 2] == '+')) {
          cout << vp[pospoin];
          pospoin++;
        } else if ((s[i] == '?') && (s[i - 2] == '-')) {
          cout << vn[negpoin];
          negpoin++;
        } else
          cout << s[i];
      }
    }
  }
  return 0;
}
