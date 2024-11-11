#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n;
  double sum = 0.0;
  double foo = 0.0, bar = 0.0, baz = 0.0, quz = 1.0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    foo += a;
    bar += 1;
    if (foo * quz == bar * baz) {
      baz = foo;
      quz = bar;
    }
  }
  cout << foo / bar << endl;
  return 0;
}
