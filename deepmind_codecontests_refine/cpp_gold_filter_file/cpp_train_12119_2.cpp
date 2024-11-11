#include <bits/stdc++.h>
using namespace std;
int main() {
  int b[100000], c = 0, d, e, f;
  int a;
  cin >> a;
  f = a;
  for (int i = 0; i < a; ++i) {
    cin >> b[i];
    if (i == b[i]) c = c + 1;
  }
  for (int i = 0; i < a; ++i) {
    if (i != b[i]) {
      if (b[b[i]] == i) {
        c = c + 2;
        cout << c;
        return 0;
      }
    }
  }
  if (c == f)
    cout << c;
  else
    cout << c + 1;
  return 0;
}
