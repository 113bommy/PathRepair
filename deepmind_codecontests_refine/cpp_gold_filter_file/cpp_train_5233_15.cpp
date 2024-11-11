#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int tt = 1;
  cin >> tt;
  while (tt--) {
    long long int a, b;
    cin >> a >> b;
    if (2 * a <= b)
      cout << a << " " << 2 * a << "\n";
    else
      cout << "-1 -1\n";
  }
  return 0;
}
