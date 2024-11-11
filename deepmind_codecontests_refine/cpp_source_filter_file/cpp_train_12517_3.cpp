#include <bits/stdc++.h>
using namespace std;
int main() {
  string p;
  cin >> p;
  int l = p.length();
  int j = 0;
  for (int i = 0; i < l; i++) {
    if (p[i] >= 33 && p[i] <= 126) {
      if (p[i] == 'H' || p[i] == 'Q' || p[i] == '9') j = 1;
    }
  }
  if (j = 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
