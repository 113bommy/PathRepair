#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 2) cout << "1\n", exit(0);
  if (n == 3) cout << "7\n", exit(0);
  if (n == 4) cout << "11\n", exit(0);
  cout << (n % 2 != 0 ? "7" + string((n - 3) / 2, '1') : string(n / 2, '1'))
       << endl;
}
