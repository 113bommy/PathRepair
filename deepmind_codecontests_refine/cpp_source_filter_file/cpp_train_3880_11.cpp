#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0), eps = 1e-9;
char gc() {
  char c;
  while ((c = getchar()) <= ' ' && c != -1)
    ;
  return c;
}
int gs(char* s) {
  if (!fgets(s, 999999, stdin)) return -1;
  int l = strlen(s);
  while (l && (s[l - 1]) <= ' ') s[--l] = 0;
  return l;
}
int c1[10], c2[10];
int main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  string s;
  cin >> s;
  string bs1 = "", bs2 = "";
  int b = 0;
  for (int i = (1), _i = (10); i < _i; i++) {
    memset((c1), (0), sizeof(c1));
    memset((c2), (0), sizeof(c2));
    string s1 = "", s2 = "";
    for (__typeof((s).begin()) j = (s).begin(), _j = (s).end(); j != _j; j++) {
      c1[*j - '0']++;
      c2[*j - '0']++;
    }
    if (c1[i] >= 1 && c2[10 - i] >= 1) {
      int ans = 0;
      c1[i]--;
      c2[10 - i]--;
      s1 += i + '0';
      s2 += 10 - i + '0';
      ans++;
      for (int j = (0), _j = (10); j < _j; j++) {
        while (c1[j] >= 1 && c2[9 - j] >= 1) {
          c1[j]--;
          c2[9 - j]--;
          s1 += j + '0';
          s2 += 9 - j + '0';
          ans++;
        }
      }
      string t1 = "", t2 = "";
      while (c1[0] >= 1 && c2[0] >= 1) {
        c1[0]--;
        c2[0]--;
        t1 += '0';
        t2 += '0';
        ans++;
      }
      for (int j = (0), _j = (10); j < _j; j++) {
        while (c1[j] >= 1) {
          c1[j]--;
          s1 += j + '0';
        }
        while (c2[j] >= 1) {
          c2[j]--;
          s2 += j + '0';
        }
      }
      s1 = t1 + s1;
      s2 = t2 + s2;
      if (ans > b) {
        b = ans;
        bs1 = s1;
        bs2 = s2;
      }
    }
  }
  {
    memset((c1), (0), sizeof(c1));
    memset((c2), (0), sizeof(c2));
    string s1 = "", s2 = "";
    for (__typeof((s).begin()) j = (s).begin(), _j = (s).end(); j != _j; j++) {
      c1[*j - '0']++;
      c2[*j - '0']++;
    }
    int ans = 0;
    while (c1[0] >= 1 && c2[0] >= 1) {
      c1[0]--;
      c2[0]--;
      s1 += '0';
      s2 += '0';
      ans++;
    }
    for (int j = (0), _j = (10); j < _j; j++) {
      while (c1[j] >= 1) {
        c1[j]--;
        s1 += j + '0';
      }
      while (c2[j] >= 1) {
        c2[j]--;
        s2 += j + '0';
      }
    }
    if (ans > b) {
      ans = b;
      bs1 = s1;
      bs2 = s2;
    }
  }
  reverse((bs1).begin(), (bs1).end());
  reverse((bs2).begin(), (bs2).end());
  cout << bs1 << '\n' << bs2 << '\n';
}
