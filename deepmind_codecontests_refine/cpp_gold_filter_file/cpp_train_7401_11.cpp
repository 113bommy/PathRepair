#include <bits/stdc++.h>
using namespace std;
const int N = 141000;
int a[N];
long long b[N];
int main() {
  int n, f = 0xfffff, m = 1, p = 0, t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]), f &= a[i];
    if (a[i] >= m && a[i - 1] != a[i]) m = a[i], p = i;
  }
  if (f == m) return cout << "NO" && 0;
  b[p] = m;
  for (int i = (p + n - 1) % n; !b[i]; i = (i + n - 1) % n)
    b[i] = b[(i + 1) % n] + a[i];
  cout << "YES" << endl;
  for (int i = 0; i < n; i++)
    if (b[i] % b[(i + 1) % n] != a[i]) {
      b[(i + 1) % n] += m;
      t = i;
      while (a[t] == a[i]) b[t] += m, t = (t - 1 + n) % n;
      b[(t + 1) % n] = m;
    }
  for (int i = 0; i < n; i++) cout << b[i] << " ";
}
