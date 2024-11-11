#include <bits/stdc++.h>
using namespace std;
void sinh() {
  freopen(
      ""
      ".inp",
      "w", stdout);
  srand(time(0));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  int n, a = 1, b = 1;
  cin >> n;
  for (int i = 0; i < 3 * n; i++) a = (a * 3) % 1000000007;
  for (int i = 0; i < n; i++) b = (b * 7) % 1000000007;
  cout << (a - b + 1000000007) % 1000000007;
  return 0;
}
