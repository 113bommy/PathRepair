#include <bits/stdc++.h>
using namespace std;

int main() {
  bool f[3];
  for (int i = 0; i < 3; ++i)
    cin >> f[i];

  f[2] = !f[2]
  cout << (f[0] == f[1] && f[1] == f[2] ? "Open" : "Close") << endl;
}