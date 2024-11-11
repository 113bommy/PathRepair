#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[10000];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  if (n % 2 == 0)
    puts("0");
  else {
    long long r = m / ((n + 1) / 2);
    long long hi = (1 << 30);
    for (int i = 0; i < n; i += 2) hi = min(hi, (long long)a[i]);
    cout << min(hi, r * k) << endl;
  }
}
