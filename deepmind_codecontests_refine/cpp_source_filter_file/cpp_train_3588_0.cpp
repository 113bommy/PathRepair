#include <bits/stdc++.h>
using namespace std;
string home, away;
char b, c;
int h[101], a[101], n, i, minute;
int main() {
  cin >> home >> away;
  cin >> n;
  while (n--) {
    cin >> minute >> b;
    if (b == 'h') {
      cin >> i >> c;
      h[i] += 1 + (c == 'r' ? 1 : 0);
      if (h[i] >= 2) {
        cout << home << " " << i << " " << minute << endl;
        h[i] = -100;
      }
    } else {
      cin >> i >> c;
      a[i] += 1 + (c == 'r' ? 1 : 0);
      if (a[i] >= 2) {
        cout << away << " " << i << " " << minute << endl;
        a[i] = -100;
      }
    }
  }
  return 0;
}
