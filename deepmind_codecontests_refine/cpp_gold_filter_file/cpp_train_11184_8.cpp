#include <bits/stdc++.h>
using namespace std;
int a, b;
int ansi, ansj;
int main() {
  cin >> a >> b;
  for (int i = 1; i < a; ++i) {
    for (int j = 1; j < a; ++j) {
      if (i * i + j * j == a * a) {
        if ((i * b) % a == 0 && (j * b) % a == 0 && j != (i * b) / a) {
          cout << "YES" << endl;
          cout << 0 << ' ' << 0 << endl;
          cout << i << ' ' << j << endl;
          cout << -(j * b) / a << ' ' << (i * b) / a << endl;
          return 0;
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
