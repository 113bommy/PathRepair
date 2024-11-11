#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 1; i <= a; i++)
    if (2 * i <= b && 4 * i <= c) {
      cout << 7 * i;
      return 0;
    }
  cout << "0";
  return 0;
}
