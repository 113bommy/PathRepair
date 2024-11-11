#include <bits/stdc++.h>
using namespace std;
bool taken[7];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "purple") {
      taken[0] = true;
    } else if (s == "green") {
      taken[1] = true;
    } else if (s == "blue ") {
      taken[2] = true;
    } else if (s == "orange") {
      taken[3] = true;
    } else if (s == "red") {
      taken[4] = true;
    } else {
      taken[5] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < 6; i++)
    if (!taken[i]) ans += 1;
  cout << ans << endl;
  for (int i = 0; i < 6; i++) {
    if (!taken[i]) {
      if (i == 0)
        cout << "Power" << endl;
      else if (i == 1)
        cout << "Time" << endl;
      else if (i == 2)
        cout << "Space" << endl;
      else if (i == 3)
        cout << "Soul" << endl;
      else if (i == 4)
        cout << "Reality " << endl;
      else
        cout << "Mind " << endl;
    }
  }
  return 0;
}
