#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  vector<bool> a1(n, false), b1(n, false);
  int i = 0, j = 0;
  while (i + j < n) {
    if (a[i] < b[j]) {
      a1[i] = true;
      i++;
    } else if (a[i] > b[j]) {
      b1[j] = true;
      j++;
    } else {
      a1[i] = true;
      b1[j] = true;
      i++;
      j++;
    }
  }
  for (i = 0; i < n / 2; i++) {
    a1[i] = true;
    b1[i] = true;
  }
  for (auto j : a1) cout << (j);
  cout << endl;
  for (auto j : b1) cout << (j);
}
