#include <bits/stdc++.h>
using namespace std;
string s;
int day[2];
int main() {
  for (int i = 0; i < 2; i++) {
    cin >> s;
    if (s == "monday")
      day[i] = 0;
    else if (s == "tuesday")
      day[i] = 1;
    else if (s == "wednesday")
      day[i] = 2;
    else if (s == "thursday")
      day[i] = 3;
    else if (s == "friday")
      day[i] = 4;
    else if (s == "saturday")
      day[i] = 5;
    else if (s == "sunday")
      day[i] = 6;
  }
  if (day[1] - day[0] == 3 || day[0] - day[1] == 1 || day[0] == day[1])
    cout << "YES";
  else if (day[1] - day[0] == -4 || day[0] - day[1] == -6)
    cout << "YES";
  else
    cout << "NO";
}
