#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  if (n >= 3) {
    if (n % 2)
      cout << n * (n - 1) * (n - 2) << '\n';
    else if (n % 3)
      cout << (n) * (n - 1) * (n - 3) << "\n";
    else
      cout << (n - 1) * (n - 2) * (n - 3) << "\n";
  } else if (n == 2)
    cout << 2 << '\n';
  else
    cout << 1 << '\n';
}
