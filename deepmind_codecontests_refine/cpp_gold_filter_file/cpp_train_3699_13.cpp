#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  while (cin >> n) {
    int b = 0, g = 0, r = 0;
    char c;
    for (int i = 0; i < n; i++) {
      cin >> c;
      if (c == 'B') {
        b++;
      }
      if (c == 'G') g++;
      if (c == 'R') r++;
    }
    if (b > 0 && g > 0 && r > 0) {
      cout << "BGR\n";
    } else if (b == 0 && g > 0 && r == 0) {
      cout << "G\n";
    } else if (b > 0 && g == 0 && r == 0) {
      cout << "B\n";
    } else if (b == 0 && g == 0 && r > 0) {
      cout << "R\n";
    } else if (b == 0 && r > 1 && g == 1) {
      cout << "BG\n";
    } else if (b > 1 && r == 0 && g == 1) {
      cout << "GR\n";
    } else if (b > 1 && r == 1 && g == 0) {
      cout << "GR\n";
    } else if (b == 0 && r == 1 && g > 1) {
      cout << "BR\n";
    } else if (b == 1 && r > 1 && g == 0) {
      cout << "BG\n";
    } else if (b == 1 && r == 0 && g > 1) {
      cout << "BR\n";
    } else if (b == 1 && g == 1 && r == 0) {
      cout << "R\n";
    } else if (b == 0 && g == 1 && r == 1) {
      cout << "B\n";
    } else if (b == 1 && g == 0 && r == 1) {
      cout << "G\n";
    } else {
      cout << "BGR\n";
    }
  }
}
