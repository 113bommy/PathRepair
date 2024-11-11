#include <bits/stdc++.h>
using namespace std;
int countbit(int n) { return (n == 0) ? 0 : (1 + countbit(n & (n - 1))); }
int lowbit(int n) { return (n ^ (n - 1)) & n; }
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
T sqr(T x) {
  return x * x;
}
int n, m, k;
int c[101], clen;
bool Nim(int k) {
  for (int i = 0; i < 8; ++i) {
    int sum = 0;
    for (int j = 0; j < clen; ++j) sum += (c[j] >> i) & 1;
    if (sum % (k + 1)) return true;
  }
  return false;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int aw = 0, bw = 0;
  for (int i = 0; i < n; ++i) {
    char str[101];
    char *pos, *pos1, *pos2;
    scanf("%s", str);
    pos = strchr(str, '-');
    pos1 = strchr(str, 'R');
    pos2 = strchr(str, 'G');
    if (pos && !pos1 && pos2) bw = 1;
    if (pos && !pos2 && pos1) aw = 1;
    if (pos1 && pos2) c[clen++] = abs(pos1 - pos2) - 1;
  }
  if (aw && bw) {
    printf("Draw\n");
    return 0;
  } else if (aw) {
    printf("First\n");
    return 0;
  } else if (bw) {
    printf("Secend\n");
    return 0;
  }
  if (Nim(k))
    printf("First\n");
  else
    printf("Second\n");
  return 0;
}
