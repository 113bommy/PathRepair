#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, k;
char s[N];
int za[N];
void buildZA() {
  memset(za, 0, sizeof za);
  za[0] = n;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) za[i] = min(r - i + 1, za[i - l]);
    while (i + za[i] < n && s[i + za[i]] == s[za[i]]) ++za[i];
    if (i + za[i] - 1 > r) l = i, r = i + za[i] - 1;
  }
  for (int i = n; i >= 1; --i) za[i] = za[i - 1];
}
int b[N];
void add(int l, int r) {
  b[l]++;
  b[r + 1]--;
}
int main() {
  scanf("%d %d\n", &n, &k);
  scanf("%s\n", s);
  n = strlen(s);
  buildZA();
  for (int i = 1; i * k <= n; ++i) {
    for (int j = 1; j <= n; j += i) {
      if (za[j] < i) break;
      if ((j - 1) / i == k - 1) {
        int d = j + i - 1;
        add(d, d + min(i, za[d + 1]));
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    b[i] += b[i - 1];
    if (b[i])
      printf("1");
    else
      printf("0");
  }
  return 0;
}
