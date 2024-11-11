#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  scanf("%lld", &n);
  long long int s = 0;
  for (long long int i = 1; i <= n; i++) {
    long long int t;
    scanf("%lld", &t);
    s += t;
  }
  long long int k = 2 * s - n * n + 3 * n;
  k /= 2;
  long long int a = k / 4, i = k % 4;
  for (long long int j = 0; j < i; j++) cout << a + j << " ";
  for (long long int j = i - 1; j < n - 1; j++) cout << a + j << " ";
}
