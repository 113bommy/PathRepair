#include <bits/stdc++.h>
using namespace std;
int a, b, r;
bool win;
string out[] = {"Second", "First"};
int main(void) {
  cin >> a >> b >> r;
  while (1) {
    a -= 2 * r;
    b -= 2 * r;
    if (a <= 0 || b <= 0) break;
    win = ~win;
  }
  cout << out[win] << endl;
  return 0;
}
