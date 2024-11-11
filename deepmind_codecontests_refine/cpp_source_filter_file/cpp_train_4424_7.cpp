#include <bits/stdc++.h>
using namespace std;
int k, d;
string a, b = "CODEFORCES";
int main() {
  cin >> a;
  if (a == b) {
    cout << "YES\n";
    return 0;
  }
  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      string h;
      for (int l = 0; l < i; l++) h += a[l];
      for (int l = j + 1; l < a.size(); l++) h += a[l];
      if (h == b) k = 1;
    }
  }
  if (k == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
