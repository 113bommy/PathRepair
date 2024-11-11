#include <bits/stdc++.h>
using namespace std;
int a[6] = {4, 8, 15, 16, 23, 42};
int main() {
  cout << "? 1 2\n? 3 4\n? 2 5\n? 3 5\n";
  int q, w, e, r;
  cin >> q >> w >> e >> r;
  do {
    if (a[0] * a[1] == q && a[2] * a[3] == w && a[1] * a[4] == e &&
        a[2] * a[4] == r) {
      cout << "! ";
      for (int i = 0; i < 6; i++) cout << a[i] << ' ';
      return 0;
    }
  } while (next_permutation(a, a + 6));
}
