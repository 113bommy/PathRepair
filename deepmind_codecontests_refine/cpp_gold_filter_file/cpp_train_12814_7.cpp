#include <bits/stdc++.h>
using namespace std;
long long int a[100000];
long long int po(long long int n, long long int exp) {
  long long int prod = 1;
  for (int i = 0; i < exp; i++) prod = (prod * n);
  return prod;
}
long long int smallestDivisor(long long int n) {
  if (n % 2 == 0) return 2;
  for (long long int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}
int main() {
  long long int n, i, j = 0, q = 0, k = 0, x = 0, m, t;
  char s[100], z[100];
  cin >> n;
  scanf("%s%s", s, z);
  for (int i = 0; i < n; i++) {
    if (s[i] != z[i]) {
      for (j = i; s[j] != z[i] && s[j] != 0; j++)
        ;
      if (s[j] == 0) q++;
      if (q != 0) {
        cout << "-1";
        return 0;
      }
      for (k = j; k > i; k--) {
        t = s[k];
        s[k] = s[k - 1];
        s[k - 1] = t;
        a[x++] = k - 1;
      }
    }
  }
  cout << x << "\n";
  for (i = 0; i < x; i++) cout << a[i] + 1 << " ";
}
