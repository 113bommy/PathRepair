#include <bits/stdc++.h>
using namespace std;
string a, b, c, d, s = "", t = "";
void change() {
  if (a[0] == 'X')
    swap(a[0], b[0]);
  else if (b[0] == 'X')
    swap(b[0], b[1]);
  else if (b[1] == 'X')
    swap(b[1], a[0]);
  else if (a[1] == 'X')
    swap(a[1], a[0]);
}
int main() {
  cin >> a >> b >> c >> d;
  for (int i = 0; i < 100; i++) {
    change();
    if (a + b == c + d) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
