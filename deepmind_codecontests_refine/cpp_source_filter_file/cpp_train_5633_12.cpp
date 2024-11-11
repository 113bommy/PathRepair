#include <bits/stdc++.h>
using namespace std;
long long get(string s) {
  long long k = 1;
  long long ret = 0;
  for (int i = 0; i < 18; i++) {
    ret += k * (s[i] - '0');
    k *= 10;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s = "000000000000000000";
  vector<long long> res;
  res.push_back(0);
  for (int i = 0; i < 18; i++) {
    for (char ch = '1'; ch <= '9'; ch++) {
      s[i] = ch;
      res.push_back(get(s));
      s[i] = '0';
    }
  }
  for (int i = 0; i < 18; i++) {
    for (int j = i + 1; j < 18; j++) {
      for (char ch1 = '1'; ch1 <= '9'; ch1++) {
        for (char ch2 = '1'; ch2 <= '9'; ch2++) {
          s[i] = ch1;
          s[j] = ch2;
          res.push_back(get(s));
          s[i] = '0';
          s[j] = '0';
        }
      }
    }
  }
  for (int i = 0; i < 18; i++) {
    for (int j = i + 1; j < 18; j++) {
      for (int k = j + 1; k < 18; k++) {
        for (char ch1 = '1'; ch1 <= '9'; ch1++) {
          for (char ch2 = '1'; ch2 <= '9'; ch2++) {
            for (char ch3 = '1'; ch3 <= '9'; ch3++) {
              s[i] = ch1;
              s[j] = ch2;
              s[k] = ch3;
              res.push_back(get(s));
              s[i] = '0';
              s[j] = '0';
              s[k] = '0';
            }
          }
        }
      }
    }
  }
  sort((res).begin(), (res).end());
  int t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    cout << lower_bound((res).begin(), (res).end(), r + 1) -
                lower_bound((res).begin(), (res).end(), l)
         << '\n';
  }
  return 0;
}
