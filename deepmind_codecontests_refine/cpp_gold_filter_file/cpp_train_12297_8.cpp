#include <bits/stdc++.h>
using namespace std;
long long x, y, z;
string s1, s2, s;
void memset_ll(long long a[], long long v, long long n) {
  for (long long i = 0; i < n; i++) a[i] = v;
}
void memset_s(char a[], char v, long long n) {
  for (long long i = 0; i < n; i++) a[i] = v;
}
int compare(const void* a, const void* b) {
  return (*(long long*)a - *(long long*)b);
}
void q_sort(long long a[], long long n) {
  qsort(a, n, sizeof(long long), compare);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, m, l, p, q, r, i, j, k, d = 0, e = 0, f = 0;
  cin >> t;
  while (t--) {
    d = 0;
    f = 0;
    e = 1;
    k = -1;
    cin >> p >> q;
    r = q - p;
    if (r % 2 == 0) {
      if (q % 2 == 0)
        l = q;
      else
        l = q * k;
      if (p % 2 == 0) {
        m = r / 2;
        n = m * k;
        n = n + l;
      } else {
        m = r / 2;
        n = m;
        n = n + l;
      }
    } else {
      if (p % 2 == 0) {
        m = (r / 2) + 1;
        n = m * k;
      } else {
        m = r / 2 + 1;
        n = m;
      }
    }
    cout << n << endl;
  }
  return 0;
}
