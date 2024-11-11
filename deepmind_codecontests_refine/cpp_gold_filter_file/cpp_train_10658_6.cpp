#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int foo = 0;
  int bar = 0;
  int baz = 0;
  int quz = 1;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    foo = foo + p;
    bar = bar + 1;
    if (foo * quz >= bar * baz) {
      baz = foo;
      quz = bar;
    }
  }
  double s = (double)baz / (double)quz;
  cout << s << endl;
  return 0;
}
