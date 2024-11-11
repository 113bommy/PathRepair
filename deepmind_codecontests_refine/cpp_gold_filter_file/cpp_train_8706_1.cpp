#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == 1 || b == 1 || c == 1)
    cout << "YES" << endl;
  else if (a == 3 && b == 3 && c == 3)
    cout << "YES" << endl;
  else if ((a == 2 && b == 2) || (b == 2 && c == 2) || (c == 2 && a == 2))
    cout << "YES" << endl;
  else {
    int cnt4 = (a == 4) + (b == 4) + (c == 4);
    int cnt2 = (a == 2) + (b == 2) + (c == 2);
    if (cnt4 == 2 && cnt2 == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
