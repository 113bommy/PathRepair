#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  int n, f = 0;
  cin >> s >> n;
  if (s == "January")
    f = 1;
  else if (s == "February")
    f = 2;
  else if (s == "March")
    f = 3;
  else if (s == "April")
    f = 4;
  else if (s == "May")
    f = 5;
  else if (s == "June")
    f = 6;
  else if (s == "July")
    f = 7;
  else if (s == "August")
    f = 8;
  else if (s == "September")
    f = 9;
  else if (s == "October")
    f = 10;
  else if (s == "November")
    f = 11;
  else if (s == "December")
    f = 12;
  int cnt = (f + n) % 12;
  if (cnt == 1)
    cout << "January" << endl;
  else if (cnt == 2)
    cout << "February" << endl;
  else if (cnt == 3)
    cout << "March" << endl;
  else if (cnt == 4)
    cout << "April" << endl;
  else if (cnt == 5)
    cout << "May" << endl;
  else if (cnt == 6)
    cout << "June" << endl;
  else if (cnt == 7)
    cout << "July" << endl;
  else if (cnt == 8)
    cout << "August" << endl;
  else if (cnt == 9)
    cout << "September" << endl;
  else if (cnt == 10)
    cout << "October" << endl;
  else if (cnt == 11)
    cout << "November" << endl;
  else if (cnt == 12)
    cout << "December" << endl;
  return 0;
}
