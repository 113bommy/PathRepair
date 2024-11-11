#include <bits/stdc++.h>
using namespace std;
long long a[100000], n, k, s = 0, d = 0;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= sqrt(n); i++)
    if (n % i == 0) {
      d += 2;
      if (i * i == n) {
        d--;
        a[s] = i;
        s++;
      } else {
        a[s] = i;
        a[s + 1] = n / i;
        s += 2;
      }
    }
  sort(a, a + s);
  if (d < k)
    cout << -1;
  else
    cout << a[k - 1];
  return 0;
}
