#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int i, j, n, m, a, b, c = 0;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) {
    cin >> a;
    if (a % 2) c++;
  }
  if (c != 0)
    cout << "First";
  else
    cout << "Second";
  return 0;
}
