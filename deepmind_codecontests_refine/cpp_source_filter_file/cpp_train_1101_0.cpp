#include <bits/stdc++.h>
using namespace std;
long long int mod(long long int x) {
  if (x < 0)
    return -x;
  else
    return x;
}
long long int binary_se(long long int a[], long long int n,
                        long long int target) {
  long long int start = 0, end = n - 1, middle;
  if (target == a[0]) return 0;
  while (start <= end) {
    middle = (start + end) / 2;
    if (target < a[middle])
      end = middle - 1;
    else if (target > a[middle])
      start = middle + 1;
    else
      return middle;
  }
  if (start > end)
    return -1;
  else
    return start;
}
long long int bo[10000001];
int main() {
  long long int b, q, l, m, k = 0;
  cin >> b >> q >> l >> m;
  long long int a[m], flag = 0, zer = 0, neg1;
  for (long long int i = 0; i < m; i++) {
    cin >> a[i];
    if (a[i] == b) flag = 1;
    if (a[i] == 0) zer = 1;
    if (a[i] == -b) neg1 = 1;
  }
  if (b == 0) {
    if (zer == 1)
      cout << 0;
    else
      cout << "inf";
    return 0;
  }
  if (mod(b) > l) {
    cout << 0;
    return 0;
  }
  if (q == -1) {
    if (neg1 == 1 && flag == 1)
      cout << 0;
    else
      cout << "inf";
    return 0;
  }
  if (zer == 1 && q == 0) {
    if (b != 0 && flag != 1)
      cout << 1;
    else
      cout << 0;
    return 0;
  }
  if (zer != 1 && q == 0) {
    cout << "inf";
    return 0;
  }
  if ((q == 1 || q == 0) && flag == 1) {
    cout << 0;
    return 0;
  }
  if ((q == 1 || q == 0) && flag != 1) {
    cout << "inf";
    return 0;
  }
  long long int term = b;
  k = 1;
  bo[0] = b;
  k = 1;
  while (mod(bo[k - 1]) <= l) {
    bo[k] = bo[k - 1] * q;
    k++;
  }
  long long int y, cou = 0;
  sort(a, a + m);
  for (long long int i = 0; i < k - 1; i++) {
    y = binary_se(a, m, bo[i]);
    if (y == -1) cou++;
  }
  cout << cou;
}
