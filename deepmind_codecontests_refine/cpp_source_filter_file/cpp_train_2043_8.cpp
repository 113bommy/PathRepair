#include <bits/stdc++.h>
using namespace std;
int A[100007];
void foo(int l, int r, int k, int st) {
  k--;
  if (k == 0) {
    for (int i = l; i <= r; i++) {
      A[i] = st;
      st++;
    }
    return;
  }
  int x = (l + r - 1) / 2;
  int num = x - l + 1;
  num = 2 * num - 1;
  if (k >= num) {
    k = k - num;
    int ptr = st + r - l;
    for (int i = l; i <= ((l + r - 1) / 2); i++) {
      A[i] = ptr;
      ptr--;
    }
    foo(((l + r - 1) / 2) + 1, r, k, st);
  } else {
    int mid = (l + r - 1) / 2;
    int st = r - (mid - st);
    foo(l, mid, k - 1, st);
    foo(mid + 1, r, 1, l);
  }
}
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  if (k % 2 == 0 || (k > (2 * n - 1))) {
    cout << -1 << endl;
    return 0;
  } else {
    foo(1, n, k, 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
