#include <bits/stdc++.h>
using namespace std;
const int maxn = 400005;
string ans[maxn];
int v[maxn];
char aa[maxn];
int aasz, vsz;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int mp[2000] = {0};
  for (int i = 0; i < s.size(); ++i) mp[s[i]]++;
  int tab[2000] = {0};
  int tmp = 0;
  for (int i = 'a'; i <= 'z'; ++i) {
    if (mp[i] & 1) {
      mp[i]--;
      v[vsz++] = i;
    }
    if (mp[i] > 0) {
      aa[aasz++] = i;
      tab[i] += (mp[i] / 2);
      tmp += tab[i];
    }
  }
  for (int i = 'A'; i <= 'Z'; ++i) {
    if (mp[i] & 1) {
      mp[i]--;
      v[vsz++] = i;
    }
    if (mp[i] > 0) {
      aa[aasz++] = i;
      tab[i] += (mp[i] / 2);
      tmp += tab[i];
    }
  }
  for (int i = '0'; i <= '9'; ++i) {
    if (mp[i] & 1) {
      mp[i]--;
      v[vsz++] = i;
    }
    if (mp[i] > 0) {
      aa[aasz++] = i;
      tab[i] += (mp[i] / 2);
      tmp += tab[i];
    }
  }
  if (vsz <= 1) {
    puts("1");
    string ans = "";
    if (vsz == 1) ans += v[0];
    for (int i = 0; i < aasz; ++i) {
      char ch = aa[i];
      string bas = "";
      for (int j = 0; j < tab[ch]; ++j) bas += ch;
      ans += bas;
    }
    int sz = ans.size();
    for (int j = sz - 1; j >= 0; j--) putchar(ans[j]);
    for (int j = (s.size() & 1 ? 1 : 0); j < sz; j++) putchar(ans[j]);
    putchar('\n');
    return 0;
  }
  while (1) {
    int x = vsz;
    if (tmp % x == 0) {
      for (int i = vsz - 1; i >= 0; --i) {
        ans[i] = "";
        ans[i] += v[i];
        int t = tmp / x;
        while (t--) {
          char ch = aa[aasz - 1];
          tab[ch]--;
          if (tab[ch] == 0) aasz--;
          ans[i] += ch;
        }
      }
      break;
    }
    char ch = aa[aasz - 1];
    tab[ch]--, tmp--;
    if (tab[ch] == 0) aasz--;
    v[vsz++] = ch;
    v[vsz++] = ch;
  }
  printf("%d\n", vsz);
  for (int i = 0; i < vsz; ++i) {
    if (i > 0) putchar(' ');
    int sz = ans[i].size();
    for (int j = sz - 1; j >= 0; j--) putchar(ans[i][j]);
    for (int j = 1; j < sz; j++) putchar(ans[i][j]);
  }
  putchar('\n');
}
