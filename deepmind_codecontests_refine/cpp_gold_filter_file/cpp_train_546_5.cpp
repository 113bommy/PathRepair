#include <bits/stdc++.h>
using namespace std;
long long temp[300005];
struct db {
  string s;
  int a, b;
};
bool cmp(db x, db y) {
  if (x.a < y.a) return true;
  return false;
}
int main() {
  long long n, q, i, j, k, l, r, t, f = 0;
  cin >> n;
  db ar[n + 2];
  for (i = 0; i < n; i++) {
    cin >> ar[i].s >> ar[i].a;
  }
  sort(ar, ar + n, cmp);
  t = n + 1;
  for (i = 0; i < n; i++) {
    if (ar[i].a > i) f = 1;
  }
  if (f)
    cout << -1 << endl;
  else {
    for (i = n - 1; i >= 0; i--) {
      for (j = n - ar[i].a - 1; j >= 0; j--) {
        if (temp[j] == 0) {
          ar[i].b = j + 1;
          temp[j] = 1;
          break;
        }
      }
    }
    for (i = 0; i < n; i++) cout << ar[i].s << " " << ar[i].b << endl;
  }
}
