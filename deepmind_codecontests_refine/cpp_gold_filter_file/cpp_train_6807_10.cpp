#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (!(n % 2)) {
    cout << -1 << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) cout << i << " ";
  cout << "\n";
  for (int i = 1; i < n; i++) cout << i << " ";
  cout << 0 << "\n";
  for (int i = 0; i < n; i++) cout << (2 * i + 1) % n << " ";
  cout << "\n";
  return 0;
}
