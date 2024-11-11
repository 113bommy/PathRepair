#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N], b[N];
int c[70];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    long long temp = a[i];
    while (temp && temp % 2 == 0) {
      b[i]++;
      temp /= 2;
    }
    c[b[i]]++;
  }
  int pos = 0;
  for (int i = 1; i <= n; i++)
    if (c[i] > c[pos]) {
      pos = i;
    }
  cout << n - c[pos] << endl;
  for (int i = 1; i <= n; i++) {
    if (b[i] != pos) printf("%lld ", a[i]);
  }
  return 0;
}
