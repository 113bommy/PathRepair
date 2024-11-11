#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c1, c2;
    c2 = n / 3;
    c1 = c2;
    if (n % 3 == 1)
      c1 = c1 + 1;
    else if (n % 3 == 2)
      c1 = c1 + 2;
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}
