#include <bits/stdc++.h>
int v[16 + 1];
int thanossplit(int st, int dr);
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  printf("%d", thanossplit(0, n - 1));
  return 0;
}
int thanossplit(int st, int dr) {
  bool sorted = 1;
  for (int i = st + 1; i <= dr; i++) {
    if (v[i] < v[i - 1]) {
      sorted = 0;
    }
  }
  if (sorted) {
    return dr - st + 1;
  }
  int mid = (st + dr) / 2;
  return std::min(thanossplit(st, mid), thanossplit(mid + 1, dr));
}
