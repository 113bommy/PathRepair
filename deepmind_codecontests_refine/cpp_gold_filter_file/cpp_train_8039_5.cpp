#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 100;
char Ma[maxn];
int Mp[maxn];
void Manacher(char s[], int len) {
  int l = 0;
  Ma[l++] = '$';
  Ma[l++] = '#';
  for (int i = 0; i < len; ++i) {
    Ma[l++] = s[i];
    Ma[l++] = '#';
  }
  Ma[l] = 0;
  int mx = 0, id = 0;
  for (int i = 0; i < l; ++i) {
    Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
    while (Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
    if (i + Mp[i] > mx) {
      mx = i + Mp[i];
      id = i;
    }
  }
}
char s[maxn];
void solve() {
  int len = strlen(s);
  int ans_len = 0;
  while (ans_len * 2 < len && s[ans_len] == s[len - 1 - ans_len]) {
    ++ans_len;
  }
  char *p = s + ans_len;
  int p_len = len - ans_len - ans_len;
  for (int i = 0; i < ans_len; ++i) {
    putchar(s[i]);
  }
  if (p_len > 0) {
    if (p_len == 1) {
      putchar(p[0]);
    } else {
      Manacher(p, p_len);
      int max_num = 0;
      int max_id = -1;
      int ss = (p_len * 2) + 2;
      for (int i = 0; i < ss; ++i) {
        if (Mp[i] > max_num) {
          if (Mp[i] == i || Mp[i] + i == ss) {
            max_num = Mp[i];
            max_id = i;
          }
        }
      }
      if (Mp[max_id] == max_id) {
        for (int k = 2; k <= (max_id << 1) - 2; k += 2) putchar(Ma[k]);
      } else {
        int k = ss - max_num - max_num + 1;
        if (k & 1) ++k;
        while (k < ss) {
          putchar(Ma[k]);
          k += 2;
        }
      }
    }
  }
  for (int i = max(len - ans_len, ans_len); i < len; ++i) {
    putchar(s[i]);
  }
  putchar('\n');
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    scanf("%s", s);
    solve();
  }
  return 0;
}
