#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    if (n <= 3 || n == 5 || n == 7)
      cout << -1;
    else if (n == 11)
      cout << -1;
    else if (n % 2 == 0)
      cout << n / 4;
    else if (n % 4 == 1)
      cout << n / 4 - 1;
    else if (n % 4 == 2)
      cout << n / 4;
    else
      cout << n / 4 - 2;
    cout << endl;
  }
}
