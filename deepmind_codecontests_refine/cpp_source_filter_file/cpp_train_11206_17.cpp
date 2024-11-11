#include <bits/stdc++.h>
using namespace std;
void mer(int *a, int *l, int ln, int *r, int rn) {
  int i = 0, j = 0, k = 0;
  while (i < ln && j < rn) {
    if (l[i] < r[j])
      a[k++] = l[i++];
    else
      a[k++] = r[j++];
  }
  while (i < ln) a[k++] = l[i++];
  while (j < rn) a[k++] = r[j++];
}
void mers(int *a, int n) {
  if (n < 2) return;
  int i, mid = n / 2;
  int l[mid], r[n - mid];
  for (i = 0; i < mid; i++) l[i] = a[i];
  for (i = mid; i < n; i++) r[i - mid] = a[i];
  mers(l, mid);
  mers(r, n - mid);
  mer(a, l, mid, r, n - mid);
}
int main() {
  long long int i = 2, n, k, pre = 0, remi;
  cin >> n >> k;
  if (k == 1)
    cout << "YES";
  else if (k >= n)
    cout << "NO" << endl;
  else if (n % 2 == 0 && k > 2)
    cout << "NO" << endl;
  else {
    while (i <= k) {
      remi = n % i;
      if (remi != (pre + 1)) {
        i = -2;
        cout << "NO" << endl;
        break;
      }
      pre = remi;
      i++;
    }
    if (i != -2) cout << "YES" << endl;
  }
}
