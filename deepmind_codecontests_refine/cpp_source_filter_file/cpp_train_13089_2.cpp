#include <bits/stdc++.h>
using namespace std;
long long n;
vector<pair<long long, string> > po;
map<long long, string> mp;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int base = 2; base <= 100000; base++) {
    long long val = base;
    string second = to_string(base) + '^';
    for (int e = 2; val * base <= 10000000000ll; e++) {
      val *= base;
      po.emplace_back(val, second + to_string(e));
      if (mp.count(val) &&
          (int)(second + to_string(e)).size() < (int)(mp[val]).size()) {
        mp[val] = second + to_string(e);
      } else if (!mp.count(val)) {
        mp[val] = second + to_string(e);
      }
    }
  }
  string res = to_string(n);
  for (const pair<long long, string> &p : po) {
    if (n >= p.first) {
      if (mp.count(n - p.first)) {
        string tmp = p.second + '+' + mp[n - p.first];
        if ((int)(tmp).size() < (int)(res).size()) {
          res = tmp;
        }
      }
      for (int i = 0; i < 10; i++) {
        if ((n - i) % p.first == 0 && mp.count((n - i) / p.first)) {
          string tmp = p.second + '*' + mp[(n - i) / p.first];
          if (i != 0) {
            tmp += '+';
            tmp += to_string(i);
          }
          if ((int)(tmp).size() < (int)(res).size()) {
            res = tmp;
          }
        }
      }
      for (int i = 2; i < 10; i++) {
        if (p.first * i <= n) {
          if (mp.count(n - p.first * i)) {
            string tmp =
                p.second + '*' + to_string(i) + '+' + mp[n - p.first * i];
            if ((int)(tmp).size() < (int)(res).size()) {
              res = tmp;
            }
          }
          if (n % (p.first * i) == 0) {
            if (mp.count(n / p.first / i)) {
              string tmp =
                  p.second + '*' + to_string(i) + '*' + mp[n - p.first * i];
              if ((int)(tmp).size() < (int)(res).size()) {
                res = tmp;
              }
            }
          }
        }
      }
      string tmp = p.second;
      if (n - p.first != 0) {
        tmp += '+';
        tmp += to_string(n - p.first);
      }
      if ((int)(tmp).size() < (int)(res).size()) {
        res = tmp;
      }
      long long c = n / p.first;
      int d = 0;
      long long asdf = c;
      while (asdf) {
        d++;
        asdf /= 10;
      }
      long long num = 0;
      for (int i = 1; i < d; i++) {
        num = num * 10 + 9;
        tmp = to_string(num) + '*' + p.second;
        assert(n - num * p.first >= 0);
        if (n - num * p.first != 0) {
          tmp += '+';
          tmp += to_string(n - num * p.first);
        }
        if ((int)(tmp).size() < (int)(res).size()) {
          res = tmp;
        }
      }
      tmp = to_string(c) + '*' + p.second;
      if (n - c * p.first != 0) {
        tmp += '+';
        tmp += to_string(n - c * p.first);
      }
      if ((int)(tmp).size() < (int)(res).size()) {
        res = tmp;
      }
    }
  }
  cout << res << endl;
  return 0;
}
