#include <bits/stdc++.h>
using namespace std;
void Prison_Transfer_solution() {
  int n, t, c;
  cin >> n >> t >> c;
  int x;
  int counter = 0;
  int out = 0;
  while (n--) {
    cin >> x;
    if (x <= t)
      counter++;
    else
      counter = 0;
    if (counter == c) {
      counter--;
      out++;
    }
  }
  cout << out;
}
void Friends_Meeting() {
  int x, y;
  cin >> x >> y;
  int diff = abs(x - y);
  int i = 1;
  int out = 0;
  for (i = 1; i <= diff / 2; i++) {
    out += i;
  }
  diff % 2 == 0 ? cout << out * 2 : cout << out * 2 + i;
}
int main() {
  Friends_Meeting();
  return 0;
}
