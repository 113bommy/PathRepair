#include <bits/stdc++.h>
using namespace std;
const int A = 6;
const int P = 1 << A;
int bit(int mask, int k) { return (mask >> k) & 1; }
void mask_print(int mask, int n = A) {
  for (int i = 0; i < n; ++i) printf("%d", bit(mask, i));
}
int c[A];
int cnt[P];
int f[P], g[P];
bool check() {
  for (int i = 0; i < P; ++i) f[i] = cnt[i];
  for (int b = 0; b < A; ++b) {
    for (int i = 0; i < P; ++i) {
      if (bit(i, b)) f[i] += f[i ^ (1 << b)];
    }
  }
  g[0] = 0;
  for (int i = 1; i < P; ++i) {
    int b = 31 - __builtin_clz(i);
    g[i] = g[i ^ (1 << b)] + c[b];
    if (g[i] < f[i]) return false;
  }
  return true;
}
const int N = (int)1e5 + 5;
char str[N], t[A + 1];
int mask[N];
int main() {
  scanf("%s", str);
  int n = strlen(str);
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; ++i) c[str[i] - 'a']++;
  int m;
  scanf("%d", &m);
  while (m--) {
    int pos;
    scanf("%d %s", &pos, t);
    --pos;
    mask[pos] = 0;
    int szt = strlen(t);
    for (int i = 0; i < szt; ++i) mask[pos] |= 1 << (t[i] - 'a');
    ++cnt[mask[pos]];
  }
  if (!check()) {
    printf("Impossible\n");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (!mask[i]) {
      mask[i] = P - 1;
    } else {
      --cnt[mask[i]];
    }
    for (int ch = 0; ch < A; ++ch) {
      if (bit(mask[i], ch) && c[ch]) {
        --c[ch];
        if (check()) {
          printf("%c", char('a' + ch));
          break;
        }
        ++c[ch];
      }
    }
  }
}
