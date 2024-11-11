#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main() {
  string s[3];
  for (long long int i = 0; i < 3; i++) {
    cin >> s[i];
  }
  long long int f = 1;
  if (s[0][0] != s[2][2]) f = 0;
  if (s[0][1] != s[2][1]) f = 0;
  if (s[0][2] != s[2][0])
    if (s[1][2] != s[1][0]) f = 0;
  if (f)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
