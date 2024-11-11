#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int p[maxn];
void solve() {
  int n;
  cin >> n;
  int fl = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    if (i > 1 && p[i - 1] >= p[i]) fl = 1;
  }
  if (n == 3 && fl == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  int __;
  cin >> __;
  while (__--) solve();
}
