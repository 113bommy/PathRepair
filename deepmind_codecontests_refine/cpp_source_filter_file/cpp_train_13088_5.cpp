#include <bits/stdc++.h>
using namespace std;
int n;
string ans;
void add(string &S, long long t) {
  char s[35];
  int len = 0;
  while (t) {
    s[++len] = t % 10;
    t /= 10;
  }
  while (len) {
    S += s[len] + '0';
    --len;
  }
}
map<long long, string> mp;
int main() {
  scanf("%lld", &n);
  if (n < 1000) {
    printf("%lld\n", n);
  } else {
    for (register long long i = 2; i <= sqrt(n + 0.5); ++i) {
      long long tot = i;
      for (int j = 2;; ++j) {
        tot *= i;
        if (tot > n) break;
        string s2 = "";
        add(s2, i);
        s2 = s2 + "^";
        add(s2, j);
        if (mp.count(tot)) {
          string s1 = mp[tot];
          if (s2.size() < s1.size()) {
            mp[tot] = s2;
          }
        } else {
          mp[tot] = s2;
        }
      }
    }
    add(ans, n);
    for (register long long i = 2; i <= sqrt(n + 0.5); ++i) {
      long long tot = i;
      for (register long long j = 2;; ++j) {
        tot = tot * i;
        if (tot > n) break;
        string res = "";
        add(res, i);
        res += "^";
        add(res, j);
        long long k = n / tot;
        for (register long long tk = k; tk >= max(1LL, k - 0); --tk) {
          long long d = n - tot * tk;
          string res2 = res;
          if (1 != tk) {
            res2 += "*";
            string res4 = "";
            add(res4, tk);
            if (mp.count(tk)) {
              if (res4.size() < mp[tk].size()) {
                res2 += res4;
              } else {
                res2 += mp[tk];
              }
            } else {
              res2 += res4;
            }
          }
          if (d) {
            res2 += "+";
            string res3 = "";
            add(res3, d);
            if (mp.count(d)) {
              if (res3.size() < mp[d].size()) {
                res2 += res3;
              } else {
                res2 += mp[d];
              }
            } else {
              res2 += res3;
            }
          }
          if (res2.size() < ans.size()) {
            ans = res2;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
