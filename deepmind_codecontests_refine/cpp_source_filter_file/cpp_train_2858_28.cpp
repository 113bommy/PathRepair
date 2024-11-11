#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, c;
  cin >> s >> n;
  if (s == "January") c = 1;
  if (s == "February") c = 2;
  if (s == "March") c = 3;
  if (s == "April") c = 4;
  if (s == "May") c = 5;
  if (s == "June") c = 6;
  if (s == "July") c = 7;
  if (s == "August") c = 8;
  if (s == "September") c = 9;
  if (s == "October") c = 10;
  if (s == "November") c = 11;
  if (s == "December") c = 12;
  int c1 = (c + n) % 12;
  if (c1 == 1)
    cout << "January" << endl;
  else if (c1 == 2)
    cout << "February" << endl;
  else if (c1 == 3)
    cout << "March" << endl;
  else if (c1 == 4)
    cout << "April" << endl;
  else if (c1 == 5)
    cout << "May" << endl;
  else if (c1 == 6)
    cout << "June" << endl;
  else if (c1 == 7)
    cout << "July" << endl;
  else if (c1 == 8)
    cout << "August" << endl;
  else if (c1 == 9)
    cout << "September" << endl;
  else if (c1 == 10)
    cout << "October" << endl;
  else if (c1 == 11)
    cout << "November" << endl;
  else if (c1 == 12)
    cout << "December" << endl;
}
