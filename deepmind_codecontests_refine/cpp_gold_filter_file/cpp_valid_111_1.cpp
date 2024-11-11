#include <bits/stdc++.h>
using namespace std;
void printsinglepairs(int numofpairs) {
  for (int i = 0; i < numofpairs; i++) {
    cout << "()";
  }
}
int main() {
  int n, j, k, t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        printsinglepairs(n);
        cout << endl;
      } else {
        for (k = 1; k <= i; k++) {
          cout << "(";
        }
        for (k = 1; k <= i; k++) {
          cout << ")";
        }
        printsinglepairs(n - i);
        cout << endl;
      }
    }
  }
  return 0;
}
