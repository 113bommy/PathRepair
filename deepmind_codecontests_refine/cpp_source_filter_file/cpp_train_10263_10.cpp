#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100001], ptra, ptrb;
  cin >> n;
  ptra = 0;
  ptrb = n - 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  while (ptra + 1 < n && a[ptra] == a[ptra + 1]) {
    ptra++;
  }
  while (ptrb - 1 >= 0 && a[ptrb] == a[ptrb - 1]) {
    ptrb--;
  }
  if (ptrb == ptra) {
    cout << 0 << endl;
  } else {
    cout << ptrb - ptra - 1 << endl;
  }
}
