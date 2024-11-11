#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("main.in", "r")) freopen("main.in", "r", stdin);
  long long nTest;
  cin >> nTest;
  while (nTest--) {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c) / 2 << '\n';
  }
  return 0;
}
