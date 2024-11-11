#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long n, k, a, b, c;
char cad[1005];
int main() {
  cin >> n;
  int ca, q = 0;
  cout << "? ";
  for (int i = 1; i <= n; i++) cout << 0;
  cout << endl;
  cin >> a;
  cout << "? ";
  cout << 1;
  for (int i = 2; i <= n; i++) cout << 0;
  cout << endl;
  cin >> b;
  q = 2;
  if (a > b) {
    int c = 0;
    for (int i = 20; i >= 0; i--) {
      if (n <= (1 << i) + c) continue;
      cout << "? ";
      ca = 0;
      for (int j = 1; j <= (1 << i) + c; j++) {
        cout << 1;
        ca++;
      }
      for (int j = (1 << i) + c + 1; j <= n; j++) ca++, cout << 0;
      assert(ca == n);
      q++;
      assert(q <= 15);
      cout << endl;
      cin >> b;
      int d = a - b;
      if (d == c + (1 << i)) c += 1 << i;
    }
    cout << "! " << c + 1 << ' ' << 1;
    cout << endl;
  } else {
    a = n - a;
    int c = 0;
    q++;
    for (int i = 20; i >= 0; i--) {
      if (n <= (1 << i) + c) continue;
      cout << "? ";
      ca = 0;
      for (int j = 1; j <= (1 << i) + c; j++) ca++, cout << 0;
      for (int j = (1 << i) + c + 1; j <= n; j++) ca++, cout << 1;
      assert(ca == n);
      q++;
      assert(q <= 15);
      cout << endl;
      cin >> b;
      int d = a - b;
      if (d == c + (1 << i)) c += 1 << i;
    }
    cout << "! " << 1 << ' ' << c + 1;
    cout << endl;
  }
  return 0;
}
