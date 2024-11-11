#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, total = 0;
  string p;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    switch (p[0]) {
      case 'C':
        total = total + 6;
        break;
      case 'I':
        total = total + 12;
        break;
      case 'D':
        total = total + 20;
        break;
      case 'T':
        total = total + 4;
        break;
      case 'O':
        total = total + 8;
        break;
    }
  }
  cout << total;
  return 0;
}
