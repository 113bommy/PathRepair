#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, sum = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * f;
}
const int MAXN = 200010;
const int MAXM = 1010;
char s[MAXM], c[MAXN], S[MAXM];
int z[MAXN], N, pos[MAXM], n, len, tot;
void get_z() {
  int l = 0, r = 0;
  for (int i = 1; i <= n + len; i++) {
    if (i > r) {
      l = i, r = i;
      while (r < n + len && s[r] == s[r - l]) r++;
      z[i] = r - l, r--;
    } else {
      int k = i - l;
      if (z[k] < r - i + 1)
        z[i] = z[k];
      else {
        l = i;
        while (r < n + len && s[r] == s[r - l]) r++;
        z[i] = r - l, r--;
      }
    }
    if (i > len && z[i]) pos[z[i]] = min(pos[z[i]], i - len + z[i] - 1);
  }
}
void get_Z() {
  int l = 0, r = 0;
  for (int i = 1; i <= n + len; i++) {
    if (i > r) {
      l = i, r = i;
      while (r < n + len && S[r] == S[r - l]) r++;
      z[i] = r - l, r--;
    } else {
      int k = i - l;
      if (z[k] < r - i + 1)
        z[i] = z[k];
      else {
        l = i;
        while (r < n + len && S[r] == S[r - l]) r++;
        z[i] = r - l, r--;
      }
    }
    if (i > len)
      if (pos[len - z[i]] <= n + len - i - z[i] + 1) {
        tot++;
        break;
      }
  }
}
int main() {
  scanf("%s", c);
  n = (int)strlen(c);
  int T;
  tot = 0;
  scanf("%d", &T);
  while (T--) {
    memset(pos, 0x3f, sizeof(pos));
    scanf("%s", s);
    len = strlen(s);
    if (len < 2) continue;
    for (int i = 0; i < n; i++) s[i + len + 1] = c[i];
    for (int i = 0; i < len; i++) S[i] = s[len - i - 1];
    for (int i = 0; i < n; i++) S[i + len + 1] = c[n - i - 1];
    S[len] = '$', s[len] = '$';
    get_z();
    for (int i = len - 1; i >= 1; i--) pos[i] = min(pos[i + 1] - 1, pos[i]);
    get_Z();
  }
  cout << tot;
  return 0;
}
