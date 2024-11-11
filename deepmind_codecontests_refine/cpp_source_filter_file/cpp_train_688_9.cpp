#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, c, d, n, k = 0, t1 = 1, t2 = 2, nextTerm;
  cin >> n;
  vector<int> v;
  if (n == 1) {
    cout << 'O' << endl;
  } else if (n == 2) {
    cout << "OO" << endl;
  } else if (n == 3) {
    cout << "OOO" << endl;
  } else {
    for (i = 3; i <= n; ++i) {
      v.push_back(t1);
      nextTerm = t1 + t2;
      t1 = t2;
      t2 = nextTerm;
    }
    for (i = 1; i <= n; i++) {
      if (i == v[k]) {
        cout << 'O';
        k++;
      } else {
        cout << 'o';
      }
    }
  }
  return 0;
}
