#include <bits/stdc++.h>
using namespace std;
int main() {
  int y;
  cin >> y;
  int k = 0, s = 0;
  for (int q = 0; q < y; q++) cin >> s, k = max(k, s);
  int w = k ^ 1;
  cout << w << '\n';
  return 0;
}
