#include <bits/stdc++.h>
using namespace std;
const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;
const int MAXN = 3e5 + 10;
int n;
int a[MAXN], even[20][MAXN], odd[20][MAXN];
inline void init() {
  for (int i = 0; i < n; ++i) {
    if (i + 1 < n) even[0][i] = max(a[i], a[i + 1]);
    if (i - 1 >= 0 && i + 1 < n) odd[0][i] = min(a[i], max(a[i - 1], a[i + 1]));
  }
  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j < n; ++j) {
      if (j + (1 << i) > n) break;
      even[i][j] = max(even[i - 1][j], even[i - 1][j + (1 << (i - 1))]);
      odd[i][j] = max(odd[i - 1][j], odd[i - 1][j + (1 << (i - 1))]);
    }
  }
}
int find_max(int lo, int hi, int (&mat)[20][MAXN]) {
  int offset = 0;
  for (; (1 << offset) <= hi - lo + 1; ++offset)
    ;
  --offset;
  return max(mat[offset][lo], mat[offset][hi - (1 << offset) + 1]);
}
int solve(int size) {
  if (size & 1) {
    if (size == 1) return *max_element(a, a + n);
    return find_max(size / 2, n - size / 2 - 1, odd);
  }
  return find_max(size / 2 - 1, n - size / 2 - 1, even);
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  init();
  for (int i = 0; i < n; ++i) printf("%d ", solve(n - i));
  printf("\n");
  return 0;
}
