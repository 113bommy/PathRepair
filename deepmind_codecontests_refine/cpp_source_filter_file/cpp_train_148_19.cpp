#include <bits/stdc++.h>
using namespace std;
int main() {
  int c[5], s = 0, i;
  for (i = 0; i < 5; i++) cin >> c[i];
  for (i = 0; i < 5; i++) s = s + c[i];
  if (s == 0)
    cout << "0";
  else if (s % 5 == 0)
    cout << s / 5;
  else
    cout << "-1";
  return 0;
}
