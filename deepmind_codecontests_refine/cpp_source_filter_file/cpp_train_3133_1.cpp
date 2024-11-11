#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a;
  cin >> b;
  int i;
  for (i = a.size() - 1; i >= 0 && a[i] == b[b.size() + i - a.size()]; i--) {
  }
  cout << a.size() + b.size() - (a.size() - i) * 2;
  return 0;
}
