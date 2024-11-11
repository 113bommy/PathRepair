#include <bits/stdc++.h>
using namespace std;
constexpr static int MAXN = 1e6;
constexpr static int B = 500;
int n;
int a[MAXN];
int cnt[MAXN];
int c[MAXN];
int calc(int k) {
  int start = 0;
  int colors = 0;
  int blocks = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[a[i]] == 0) {
      cnt[a[i]]++;
      colors++;
      if (colors == k + 1) {
        blocks++;
        colors = 1;
        for (int j = start; j < i; j++)
          if (cnt[a[j]]) cnt[a[j]] = 0;
        start = i;
      }
    }
  }
  blocks++;
  for (int j = start; j < n; j++)
    if (cnt[a[j]]) cnt[a[j]] = 0;
  return blocks;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int k = 1; k <= B && k <= n; k++) c[k] = calc(k);
  int maxblocks = n / B + 1;
  int k = n;
  for (int blocks = 1; blocks <= maxblocks; blocks++) {
    int low = B, high = n;
    while (low < high) {
      int mid = (low + high) / 2;
      if (calc(mid) <= blocks)
        high = mid;
      else
        low = mid + 1;
    }
    for (; k >= low && k >= B; k--) c[k] = blocks;
    if (k < B) break;
  }
  for (int k = 1; k <= n; k++) printf("%d ", c[k]);
  printf("\n");
}
