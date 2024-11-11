#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  string s;
  cin >> n;
  getline(cin, s);
  while (n > 0) {
    n--;
    getline(cin, s);
    int a[13] = {0}, k = 0;
    for (int i = 0; i < 12; i++)
      if (s[i] == 'X' && a[1] == 0) {
        a[1] = 1;
        k++;
      }
    for (int i = 0; i < 12; i++)
      if (s[i] == 'X' && a[2] == 0 && s[(i + 6) % 12] == 'X') {
        a[2] = 1;
        k++;
      }
    for (int i = 0; i < 12; i++)
      if (s[i] == 'X' && a[3] == 0 && s[(i + 4) % 12] == 'X' &&
          s[(i + 8) % 12] == 'X') {
        a[3] = 1;
        k++;
      }
    for (int i = 0; i < 12; i++)
      if (s[i] == 'X' && a[4] == 0 && s[(i + 3) % 12] == 'X' &&
          s[(i + 6) % 12] == 'X' && s[(i + 9) % 12] == 'X') {
        a[4] = 1;
        k++;
      }
    for (int i = 0; i < 12; i++)
      if (s[i] == 'X' && a[6] == 0 && s[(i + 2) % 12] == 'X' &&
          s[(i + 4) % 12] == 'X' && s[(i + 6) % 12] == 'X' &&
          s[(i + 8) % 12] == 'X' && s[(i + 10) % 12] == 'X') {
        a[6] = 1;
        k++;
      }
    for (int i = 0; i < 12; i++)
      if (s[i] == 'X' && a[12] == 0 && s[(i + 1) % 12] == 'X' &&
          s[(i + 2) % 12] == 'X' && s[(i + 3) % 12] == 'X' &&
          s[(i + 4) % 12] == 'X' && s[(i + 5) % 12] == 'X' &&
          s[(i + 6) % 12] == 'X' && s[(i + 7) % 12] == 'X' &&
          s[(i + 8) % 12] == 'X' && s[(i + 9) % 12] == 'X' &&
          s[(i + 10) % 12] == 'X' && s[(i + 11) % 12] == 'X') {
        a[12] = 1;
        k++;
      }
    cout << k << ' ';
    for (int i = 1; i <= 12; i++)
      if (a[i]) cout << i << 'x' << 12 / i << ' ';
    cout << endl;
  }
}
