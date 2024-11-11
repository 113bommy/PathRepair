#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100;
const int K = 3;
const int KBITS = 1 << K;
int bs[MAX_N];
int used[KBITS];
int ntobits(int n) {
  int bits = 0;
  for (int bi = 1; n > 0; bi <<= 1, n /= 10)
    if (n % 10) bits |= bi;
  return bits;
}
int main() {
  int n;
  scanf("%d", &n);
  memset(used, -1, sizeof(used));
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    int abits = ntobits(ai);
    if (used[abits] < 0) used[abits] = ai;
  }
  int m = 0;
  if (used[0] >= 0) bs[m++] = used[0];
  if (used[1] >= 0) bs[m++] = used[1];
  if (used[2] >= 0) bs[m++] = used[2];
  if (used[4] >= 0) bs[m++] = used[4];
  if (used[3] >= 0 && used[1] < 0 && used[2] > 0) bs[m++] = used[3];
  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    if (i) putchar(' ');
    printf("%d", bs[i]);
  }
  putchar('\n');
  return 0;
}
