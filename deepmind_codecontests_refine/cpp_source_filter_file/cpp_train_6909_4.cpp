#include <bits/stdc++.h>
using namespace std;
unsigned long long a[100 * 1000 + 20];
int main() {
  int n, x;
  unsigned long long s = 0;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) cin >> a[i];
  unsigned long long min = a[1];
  int mini = 1;
  int P = x - 1;
  if (P == 0) P = n;
  while (P != x) {
    if (a[P] < min) {
      min = a[P];
      mini = P;
    }
    P--;
    if (P == 0) P = n;
  }
  int p = x;
  while (p != mini) {
    if (a[p] == 0) {
      a[p] = s;
      for (int i = 1; i <= n; i++) cout << a[i] << " ";
      return 0;
    }
    a[p]--;
    s++;
    p--;
    if (p == 0) p = n;
  }
  unsigned long long k = a[mini];
  for (int i = 1; i <= n; i++) a[i] -= k;
  a[mini] = k * n + s;
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
