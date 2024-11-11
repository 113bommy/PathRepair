#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, l, n, m, t;
  string a, b;
  char c[100005];
  cin >> a;
  if (a.size() == 1) {
    cout << 1 << endl;
    return 0;
  }
  c[a.size() - 1] = a[a.size() - 1];
  for (i = a.size() - 2; i >= 0; i--) {
    if (a[i] > c[i + 1])
      c[i] = a[i];
    else
      c[i] = c[i + 1];
  }
  b = "";
  for (i = 0; i < a.size(); i++) {
    if (c[i] == a[i]) b = b + c[i];
  }
  cout << b << endl;
  return 0;
}
