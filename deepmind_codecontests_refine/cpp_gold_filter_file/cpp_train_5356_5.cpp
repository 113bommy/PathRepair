#include <bits/stdc++.h>
using namespace std;
map<int, int> tt;
int main() {
  int a, b;
  cin >> a >> b;
  int r = 0;
  for (int g = 0; g < b; g++) {
    int d;
    cin >> d;
    if (tt[d % a] == 0) {
      tt[d % a] = 1;
    } else {
      cout << g + 1;
      r = 1;
      break;
    }
  }
  if (r == 0) cout << -1;
  return 0;
}
