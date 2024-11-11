#include <bits/stdc++.h>
using namespace std;
const int nn = 1100000;
int f[nn], L;
char S[nn];
int main() {
  scanf("%s", S + 1);
  L = strlen(S + 1);
  while (f[2] < L - 1 && S[1 + f[2]] == S[2 + f[2]]) f[2]++;
  int l = 2, r = l + f[2] - 1;
  for (int i = 3; i <= (int)(L); ++i) {
    if (i > r) {
      l = i;
      r = i - 1;
      while (r < L && S[r + 1] == S[r + 1 - l + 1]) r++;
      f[i] = r - l + 1;
    } else {
      if (i + f[i - l + 1] - 1 <= r) {
        f[i] = f[i - l + 1];
        continue;
      }
      l = i;
      while (r < L && S[r + 1] == S[r + 1 - l + 1]) r++;
      f[i] = r - l + 1;
    }
  }
  int mx = 0, x = 0;
  for (int i = 2; i <= (int)(L); ++i) {
    if (i + f[i] - 1 == L && i + mx > L) {
      x = L - i + 1;
      break;
    }
    mx = max(mx, f[i]);
  }
  if (x) {
    for (int i = 1; i <= (int)(x); ++i) putchar(S[i]);
    puts("");
  } else
    puts("Just a legend");
  return 0;
}
