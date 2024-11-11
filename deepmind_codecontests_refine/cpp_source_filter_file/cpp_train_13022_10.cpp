#include <bits/stdc++.h>
using namespace std;
int a, b, c[101], d, i, f, g, h, k, l, j;
set<int> st;
set<int>::iterator it;
int main() {
  cin >> a >> b;
  c[b] = {0};
  for (i = 1; i <= a; i++) {
    cin >> g >> f;
    for (j = g; j <= f; j++) {
      c[j] = 1;
    }
  }
  for (i = 1; i < b; i++) {
    if (c[i] == 0) h++;
  }
  cout << h << endl;
  for (i = 1; i < b; i++) {
    if (c[i] == 0) cout << i << " ";
  }
}
