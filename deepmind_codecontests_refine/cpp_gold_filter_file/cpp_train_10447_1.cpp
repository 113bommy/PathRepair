#include <bits/stdc++.h>
using namespace std;
const int maxlen = 1000000 + 50;
char s[maxlen] = {0};
char ss[30] = {0};
int len = 0;
int n;
short link[1 << 26] = {0};
int Bit[10001] = {0};
int Cnt[10001] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin >> s + 1;
  len = strlen(s + 1);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ss;
    for (int j = 0; j < strlen(ss); j++) {
      Bit[i] |= 1 << (ss[j] - 'a');
    }
    link[Bit[i]] = i;
  }
  for (int i = 1; i <= len; i++) {
    int t = 0;
    for (int j = i; j <= len; j++) {
      if (s[i - 1] == s[j]) break;
      t |= 1 << (s[j] - 'a');
      if (!(t >> (s[j + 1] - 'a') & 1)) Cnt[link[t]]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << Cnt[link[Bit[i]]] << endl;
  }
  return 0;
}
