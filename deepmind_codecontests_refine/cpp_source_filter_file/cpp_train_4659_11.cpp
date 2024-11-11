#include <bits/stdc++.h>
using namespace std;
long long int cnt = 0;
long int a[66666];
int poi1;
int poi2;
int merge(int l, int r) {
  if (l == r - 1) return 0;
  int mid = (l + r) / 2;
  merge(l, mid);
  merge(mid, r);
  int b[r - l];
  poi1 = l;
  poi2 = mid;
  for (int i = 0; i < r - l; i++) {
    if (poi1 >= mid) {
      b[i] = a[poi2++];
    } else if (poi2 >= r) {
      b[i] = a[poi1++];
      cnt += poi2 - mid;
    } else if (a[poi1] == a[poi2]) {
      b[i] = a[poi1++];
      cnt += poi2 - mid;
    } else if (a[poi1] < a[poi2]) {
      b[i] = a[poi1++];
      cnt += poi2 - mid;
    } else {
      b[i] = a[poi2++];
    }
  }
  for (int i = 0; i < r - l; i++) {
    a[i + l] = b[i];
  }
  return 0;
}
int main() {
  long long int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  merge(0, n);
  if (n % 2 == 1) {
    if (cnt % 2 == 1) {
      cout << "Petr";
    } else
      cout << "Um_nik";
  } else {
    if (n % 2 == 0) {
      cout << "Petr";
    } else
      cout << "Um_nik";
  }
}
