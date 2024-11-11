#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  getline(cin, s);
  int week[] = {52, 52, 52, 52, 52, 52, 53};
  if (s == " of week")
    cout << week[n - 1] << endl;
  else {
    if (n == 30)
      cout << 11 << endl;
    else if (n == 31)
      cout << 7 << endl;
    else
      cout << 12 << endl;
  }
  return 0;
}
