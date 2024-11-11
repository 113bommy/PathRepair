#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    if (n <= 2)
      cout << 1 << endl;
    else if (n == 3)
      cout << 2 << endl;
    else
      cout << (n + 1) / 2 << endl;
  }
}
