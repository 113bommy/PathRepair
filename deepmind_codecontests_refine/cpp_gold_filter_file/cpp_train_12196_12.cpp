#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n;
  cin >> n;
  if (n == 0)
    cout << "15" << endl;
  else if (n == 1)
    cout << "14" << endl;
  else if (n == 2)
    cout << "12" << endl;
  else if (n == 3)
    cout << "13" << endl;
  else if (n == 4)
    cout << "8" << endl;
  else if (n == 5)
    cout << "9" << endl;
  else if (n == 6)
    cout << "10" << endl;
  else if (n == 7)
    cout << "11" << endl;
  else if (n == 8)
    cout << "0" << endl;
  else if (n == 9)
    cout << "1" << endl;
  else if (n == 10)
    cout << "2" << endl;
  else if (n == 11)
    cout << "3" << endl;
  else if (n == 12)
    cout << "4" << endl;
  else if (n == 13)
    cout << "5" << endl;
  else if (n == 14)
    cout << "6" << endl;
  else if (n == 15)
    cout << "7" << endl;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
