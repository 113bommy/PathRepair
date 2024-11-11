#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, f;
  string a;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (a[i] == a[j]) {
        f = 1;
        break;
      }
    }
    if (f == 0) d++;
    f = 0;
  }
  if (d % 2 == 0)
    cout << "IGNORE HIM!";
  else
    cout << "CHAT WITH HER!";
}
