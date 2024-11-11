#include <bits/stdc++.h>
long long n, i, k, j, t, b;
char a[2500];
bool s;
using namespace std;
int main() {
  k = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 'H') k++;
  }
  b = n - k;
  for (i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
  for (i = 1; i <= 2 * n; i++)
    if (i + k <= 2 * n) {
      t = 0;
      for (j = i; j <= i + k; j++)
        if (a[j] != 'H') t++;
      if (t < b) b = t;
    }
  cout << b << endl;
  return 0;
}
