#include <bits/stdc++.h>
using namespace std;
long long k1, k, n, mas[100000], q, m, a[100000], mas1[100000];
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> mas[i] >> mas1[i];
  if (n == 1) {
    cout << 1;
    return 0;
  }
  a[0] = mas[0];
  for (long long i = 1; i < n; i++) {
    a[i] = mas[i] - mas[i - 1];
  }
  k = 2;
  for (long long i = 1; i < n - 1; i++) {
    if (a[i] > mas1[i]) {
      k++;
      a[i] = a[i] - mas1[i];
    } else if (a[i + 1] > mas1[i]) {
      k++;
      a[i + 1] = a[i + 1] - mas1[i];
    }
  }
  cout << k;
}
