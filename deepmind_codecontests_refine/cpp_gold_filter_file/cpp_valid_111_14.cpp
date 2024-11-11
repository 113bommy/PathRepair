#include <bits/stdc++.h>
using namespace std;
void pB(int a) {
  for (int i = a; i > 0; i--) {
    cout << "("
         << ")";
  }
}
void pBOC(int x, int y) {
  for (int i = 0; i < x; i++) {
    cout << "(";
  }
  pB(y - x);
  for (int i = 0; i < x; i++) {
    cout << ")";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      pBOC(i, n);
      cout << "\n";
    }
  }
  return 0;
}
