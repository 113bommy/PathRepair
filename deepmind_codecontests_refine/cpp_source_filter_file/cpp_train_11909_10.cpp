#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n & 1) {
    for (int i = 0; i < n; i++) cout << i << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << i << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << (2 * 1) % n << ' ';
  } else
    cout << -1;
  return 0;
}
