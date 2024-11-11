#include <bits/stdc++.h>
using namespace std;
int f[600005];
void generate(string s) {
  f[0] = -1;
  f[1] = 0;
  int pos = 2;
  int cc = 0;
  while (pos < s.size()) {
    if (s[pos - 1] == s[cc]) {
      cc++;
      f[pos] = cc;
      pos++;
    } else if (cc > 0) {
      cc = f[cc];
    } else {
      f[pos] = 0;
      pos++;
    }
  }
}
int kmp(string s1, string s2) {
  int i;
  int pos;
  i = pos = 0;
  int val = 0;
  while (i + pos < s1.size()) {
    if (s2[i] == s1[pos + i]) {
      i++;
      if (i == s2.size()) {
        return pos;
      }
    } else {
      pos = pos + i - f[i];
      if (f[i] > -1) {
        i = f[i];
      } else {
        i = 0;
      }
    }
  }
  return -1;
}
int kmp1(string s1, string s2) {
  int i;
  int pos;
  i = pos = 0;
  int val = 0;
  while (i + pos < s1.size()) {
    if (s2[i] == s1[pos + i]) {
      i++;
    } else {
      pos = pos + i - f[i];
      if (f[i] > -1) {
        i = f[i];
      } else {
        i = 0;
      }
    }
  }
  return i;
}
int main() {
  int ar[] = {0, 1, 2};
  string s[3];
  cin >> s[0] >> s[1] >> s[2];
  int ans = 10000000;
  while (1) {
    string s1 = s[ar[0]];
    string s2 = s[ar[1]];
    string s3 = s[ar[2]];
    generate(s2);
    int val = 0;
    if (s1.size() > s2.size()) {
      val = kmp(s1, s2);
    }
    string ss = "", ss2 = "";
    if (val) {
      ss = s1;
    } else {
      val = kmp1(s1, s2);
      for (int i = 0; i < s1.size() - val; i++) {
        ss += s1[i];
      }
      for (int j = 0; j < s2.size(); j++) {
        ss += s2[j];
      }
    };
    generate(s3);
    val = 0;
    if (ss.size() > s3.size()) {
      val = kmp(ss, s3);
    }
    if (val) {
      ans = min(ans, (int)ss2.size());
    } else {
      val = kmp1(ss, s3);
      ans = min(ans, (int)(ss.size() + s3.size()) - val);
    }
    if (!next_permutation(ar, ar + 3)) break;
  }
  cout << ans << endl;
}
