#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<string> v;
  string num = "";
  for (long long i = 0; i < s.length(); i++) {
    long long o = int(s[i]);
    if (!(o >= 97 && o <= 122)) {
      num.push_back(s[i]);
    } else {
      if (num != "") v.push_back(num);
      num = "";
    }
  }
  if (num != "") {
    v.push_back(num);
  }
  vector<long long> dec;
  vector<long long> num1;
  for (long long i = 0; i < v.size(); i++) {
    string r = v[i];
    reverse(r.begin(), r.end());
    long long p = 0;
    long long l = 0;
    for (long long j = 0; j < r.size(); j++) {
      if (r[j] != '.') {
        p++;
      } else if (r[j] == '.')
        break;
    }
    if (p == 2) {
      long long q = 0;
      long long u = 0;
      long long l = 0;
      for (long long j = 0; j < r.size(); j++) {
        if (r[j] != '.') {
          q++;
        } else {
          l++;
          if (q != 3 && l > 1) {
            u++;
            break;
          }
          q = 0;
        }
      }
      if (q > 3) {
        u++;
      }
      if (u == 0) {
        long long deci = 0;
        ;
        reverse(r.begin(), r.end());
        for (long long j = r.size() - 2; j < r.size(); j++) {
          if (r[j] != '.') {
            deci = deci * 10 + int(r[j]) - '0';
          } else
            break;
        }
        dec.push_back(deci);
        long long num = 0;
        for (long long j = 0; j < r.size() - 3; j++) {
          if (r[j] != '.') num = num * 10 + int(r[j]) - '0';
        }
        num1.push_back(num);
      }
    }
    if (p == 3 || v[i].size() <= 3) {
      long long q = 0;
      long long u = 0;
      for (long long j = 0; j < r.size(); j++) {
        if (r[j] != '.') {
          q++;
        } else {
          if (q != 3) {
            u++;
            break;
            q = 0;
          }
          q = 0;
        }
      }
      if (q > 3) {
        u++;
      }
      if (u == 0) {
        reverse(r.begin(), r.end());
        {
          long long num = 0;
          for (long long j = 0; j < r.size(); j++) {
            if (r[j] != '.') {
              num = num * 10 + int(r[j]) - '0';
            }
          }
          num1.push_back(num);
        }
      }
    }
  }
  long long sum = 0;
  for (long long i = 0; i < dec.size(); i++) {
    long long num = 0;
    sum += dec[i];
  }
  long long x = sum;
  long long pum = 0;
  long long y = 0;
  for (long long i = 0; i < num1.size(); i++) {
    pum += num1[i];
  }
  y = pum;
  long long u = 0;
  if (sum >= 100) {
    u = sum / 100;
    sum = sum - 100;
    x = sum;
  }
  pum += u;
  string s1;
  s1 = "";
  y = pum;
  while (pum > 0) {
    long long o = pum % 10;
    pum = pum / 10;
    s1.push_back(char(o + int('0')));
  }
  string s2 = "";
  while (sum > 0) {
    long long o = sum % 10;
    sum = sum / 10;
    s2.push_back(char(o + int('0')));
  }
  for (long long i = 3; i < s1.length(); i = i + 4) {
    s1.insert(i, ".");
  }
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  if (x <= 9 && x != 0) {
    s2.insert(0, "0");
  }
  if (y == 0) s1.insert(0, "0");
  if (x != 0)
    cout << s1 + "." + s2 << endl;
  else
    cout << s1;
}
