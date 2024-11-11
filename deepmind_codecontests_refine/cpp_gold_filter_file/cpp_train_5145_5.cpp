#include <bits/stdc++.h>
using namespace std;
int n, v[5 * 100001], freq[100001], val;
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    freq[val]++;
  }
  int idx = 0;
  for (int i = 0; i < 100001; i++) {
    for (int j = 0; j < freq[i]; j++) {
      v[idx++] = i;
    }
  }
  int ans = 0;
  int mid = n >> 1;
  int l = 0, r = (n >> 1);
  while (l < mid && r < n) {
    if (2 * v[l] <= v[r]) {
      l++;
      r++;
      ans++;
    } else {
      r++;
    }
  }
  printf("%d\n", n - ans);
  return 0;
}
