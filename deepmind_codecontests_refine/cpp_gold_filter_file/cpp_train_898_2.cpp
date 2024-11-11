#include <bits/stdc++.h>
using namespace std;
long long z, x, h, s;
string s1, s0;
int main() {
  cin >> z;
  for (int i = 1; i <= z; i++) {
    cin >> s0 >> s1;
    if (s1 == "hard")
      h++;
    else if (s1 == "soft")
      s++;
  }
  if (h == 1 && s == 1) {
    cout << 2 << endl;
    return 0;
  }
  if (h >= s)
    x = (h + h) - 1;
  else
    x = (s + s) - 1;
  for (int i = 0; i <= 15; i++)
    if (i * i >= x) {
      cout << i << endl;
      break;
    }
}
