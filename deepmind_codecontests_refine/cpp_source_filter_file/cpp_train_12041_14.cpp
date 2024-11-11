#include <bits/stdc++.h>
using namespace std;
void solve() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  if (n <= 5)
    cout << "-1" << endl;
  else {
    for (int i = 2; i <= n / 2; i++) cout << 1 << " " << i << endl;
    for (int i = n / 2 + 1; i <= n; i++) cout << 2 << " " << i << endl;
  }
  for (int i = 2; i <= n; i++) cout << i - 1 << " " << i << endl;
}
int main() {
  solve();
  int mk;
  if (scanf("%d", &mk) == EOF) return 0;
  return 0;
}
