#include <bits/stdc++.h>
using namespace std;
long long int countdistinct(long long int a[], long long int n) {
  long long int i;
  long long int count = 0;
  sort(a, a + n);
  for (i = 0; i < n; i++)
    if (a[i] != a[i - 1]) count++;
  return count;
}
int main() {
  long long int n;
  cin >> n;
  long long int i, j, k, l;
  long long int a[100000];
  if (n <= 15) {
    long long int count = 0;
    for (i = 0; i <= n; i++)
      for (j = 0; j <= n; j++)
        for (k = 0; k <= n; k++)
          for (l = 0; l <= n; l++) {
            if (i + j + k + l == n) {
              a[count] = i + 5 * j + 10 * k + 50 * l;
              count++;
            }
          }
    cout << countdistinct(a, count) + 1;
  } else
    cout << 49 * n - 247;
}
