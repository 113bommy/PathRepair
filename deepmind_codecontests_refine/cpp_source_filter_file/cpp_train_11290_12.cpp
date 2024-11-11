#include <bits/stdc++.h>
bool check(int n, int a[]) {
  int i, j, k;
  int *in = new int[n];
  int nodd = 0, neven = 0;
  int p, q;
  if (n <= 2) return 0;
  if (n == 3) return a[0] - a[1] == a[1] - a[2];
  if (a[0] % 2 == a[n - 1] % 2) return 1;
  for (i = 0; i < n; i++) {
    in[a[i]] = i;
    if (a[i] % 2)
      nodd++;
    else
      neven++;
  }
  for (p = 1; p < n; p++) {
    if ((a[p] + a[0]) % 2) {
      break;
    }
  }
  for (q = n - 2; q >= 0; q--) {
    if ((a[q] + a[n - 1]) % 2) {
      break;
    }
  }
  q++;
  long long v = (q - p) * (long long)(q - p - 1) / 2;
  if (v > n && v > 6) return 1;
  for (i = p; i < q; i++) {
    for (j = i + 1; j < q; j++) {
      k = a[j] + a[j] - a[i];
      if (k >= 0 && k < n && in[k] > j) {
        return 1;
      }
      k = a[i] - a[j] + a[i];
      if (k >= 0 && k < n && in[k] < i) {
        return 1;
      }
    }
  }
  int *odd, *even;
  odd = new int[nodd];
  even = new int[neven];
  j = k = 0;
  for (i = 0; i < n; i++) {
    if (a[i] % 2)
      odd[j++] = a[i] / 2;
    else
      even[k++] = a[i] / 2;
  }
  bool r = check(j, odd) || check(k, even);
  delete[] odd;
  delete[] even;
  delete[] in;
  return r;
}
int main() {
  int i, j, k;
  int n;
  int *a;
  while (scanf("%d", &n) == 1 && n) {
    a = new int[n];
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      a[i]--;
    }
    puts(check(n, a) ? "YES" : "NO");
    delete[] a;
  }
}
