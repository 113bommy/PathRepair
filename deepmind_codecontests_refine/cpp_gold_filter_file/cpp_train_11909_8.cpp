#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0)
    cout << -1 << '\n';
  else {
    for (int i = 0; i < n; i++) {
      cout << i << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
      cout << i << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
      cout << (i + i) % n << ' ';
    }
    cout << '\n';
  }
}
