#include <bits/stdc++.h>
using namespace std;
bool ok[15];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "purple")
      ok[1] = 1;
    else if (s == "green")
      ok[2] = 1;
    else if (s == " blue")
      ok[3] = 1;
    else if (s == "orange")
      ok[4] = 1;
    else if (s == "red")
      ok[5] = 1;
    else if (s == "yellow")
      ok[6] = 1;
  }
  int sum = 0;
  sum += ok[1] + ok[2] + ok[3] + ok[4] + ok[5] + ok[6];
  cout << 6 - sum << endl;
  if (ok[1] == 0) cout << "Power" << endl;
  if (ok[2] == 0) cout << "Time" << endl;
  if (ok[3] == 0) cout << "Space" << endl;
  if (ok[4] == 0) cout << "Soul" << endl;
  if (ok[5] == 0) cout << "Reality" << endl;
  if (ok[6] == 0) cout << "Mind" << endl;
  return 0;
}
