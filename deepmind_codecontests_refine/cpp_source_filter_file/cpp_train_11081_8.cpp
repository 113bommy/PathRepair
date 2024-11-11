#include <bits/stdc++.h>
using namespace std;
int src(int ar[10], int r, int key) {
  for (int i = 0; i < r; i++) {
    if (ar[i] == key) return i;
  }
}
int main() {
  string a, b, c, d;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  int l1 = a.length() - 2;
  int l2 = b.length() - 2;
  int l3 = c.length() - 2;
  int l4 = d.length() - 2;
  int ar[] = {l1, l2, l3, l4};
  char ar1[] = {'A', 'B', 'C', 'D'};
  vector<int> v(ar, ar + 4);
  sort(v.begin(), v.end());
  int m, n, f1 = 0, f2 = 0;
  if ((2 * v[0] == v[1]) && (2 * v[0] == v[2]) && (2 * v[0] == v[3])) {
    f1 = 1;
    m = v[0];
  }
  if ((2 * v[2] == v[3]) && (2 * v[1] == v[3]) && (2 * v[0] == v[3])) {
    f2 = 1;
    n = v[3];
  }
  if (f1 == 0 && f2 == 1) {
    int i = src(ar, 4, n);
    cout << ar1[i];
  } else if (f1 == 1 && f2 == 0) {
    int i = src(ar, 4, m);
    cout << ar1[i];
  } else
    cout << 'C';
}
