#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
unsigned long long n, Max, a[N], c[N], f[N];
void Input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    Max = max(Max, a[i]), c[a[i]]++;
  }
}
void Solve() {
  for (int i = 2; i <= Max; i++) c[i] = max(c[i - 1], c[i - 2] + c[i] * i);
  cout << c[Max] << '\n';
}
int main() {
  Input();
  Solve();
  return 0;
}
