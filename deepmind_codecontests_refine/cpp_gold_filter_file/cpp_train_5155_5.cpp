#include <bits/stdc++.h>
using namespace std;
long long n, vmin, res;
long long a[400000];
void laymax(long long &a, int b) {
  if (a < b) a = b;
}
void xl() {
  int i, j;
  j = 0;
  res = 0;
  for (i = 0; i < n; i++) {
    if (j < i) j = i;
    while (j < i + n && a[j] > vmin) j++;
    laymax(res, j - i);
  }
  printf("%I64d", res + vmin * n);
}
void laymin(long long &a, int b) {
  if (a > b) a = b;
}
void docdl() {
  vmin = int(1e9 + 7);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    laymin(vmin, a[i]);
    a[i + n] = a[i];
  }
}
int main() {
  docdl();
  xl();
  return 0;
}
