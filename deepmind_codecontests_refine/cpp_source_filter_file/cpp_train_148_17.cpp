#include <bits/stdc++.h>
using namespace std;
int main() {
  int s = 0;
  int c[5];
  for (int i = 0; i < 5; ++i) cin >> c[i], s += c[i];
  if (s % 5 == 0)
    cout << s / 5 << endl;
  else
    cout << -1 << endl;
}
