#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long int n, a, b, c;
  cin >> n;
  if (n == 0)
    cout << "O-|-OOOO";
  else {
    while (n > 0) {
      a = n % 10;
      if (a >= 5) {
        cout << "-O|";
        b = a - 5;
        for (int i = 0; i < b; i++) cout << "O";
        cout << "-";
        b = 4 - b;
        for (int i = 0; i < b; i++) cout << "O";
      } else {
        cout << "O-|";
        b = a;
        for (int i = 0; i < b; i++) cout << "O";
        cout << "-";
        b = 4 - a;
        for (int i = 0; i < b; i++) cout << "O";
      }
      n = n / 10;
      cout << '\n';
    }
  }
  return 0;
}
