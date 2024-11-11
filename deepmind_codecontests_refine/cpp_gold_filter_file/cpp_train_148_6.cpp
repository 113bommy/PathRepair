#include <bits/stdc++.h>
using namespace std;
int main() {
  int c = 0, k;
  for (int i = 0; i < 5; i++) {
    cin >> k;
    c += k;
  }
  if (c % 5 == 0 && c > 0)
    cout << c / 5;
  else
    cout << "-1";
}
