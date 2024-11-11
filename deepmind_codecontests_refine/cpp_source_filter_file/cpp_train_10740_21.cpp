#include <bits/stdc++.h>
using namespace std;
int q;
void solve(int a, int b, int c) {
  for (int i = 1; i <= b; i++) {
    cout << i * 2 << " " << c << "\n";
  }
  for (int i = 0; i <= b; i++) {
    cout << i * 2 + 1 << " " << c << "\n";
  }
  a = a - b;
  for (int i = 1; i <= a / 2; i++) {
    cout << i * 2 << " " << c - 1 << "\n";
    cout << i * 2 << " " << c + 1 << "\n";
  }
  if (!a & 1) {
    cout << (a / 2 + 1) * 2 << " " << c - 1 << "\n";
  }
}
int main() {
  cin >> q;
  int a, b;
  while (q--) {
    cin >> a >> b;
    if (a * 3 + 1 < b || a > b * 3 + 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (a > b) {
      solve(a, b, 2);
    } else if (a < b) {
      solve(b, a, 3);
    } else {
      for (int i = 1; i <= b; i++) {
        cout << i * 2 << " " << 3 << "\n";
        cout << i * 2 + 1 << " " << 3 << "\n";
      }
    }
  }
}
