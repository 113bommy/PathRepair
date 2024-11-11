#include <bits/stdc++.h>
using namespace std;
inline void filee() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int main() {
  int a, b;
  cin >> a >> b;
  int c = b;
  if (a == b) {
    cout << a - 1 << endl;
  } else {
    for (int i = 2; i <= a - c; i++) {
      b += i;
    }
    cout << b << endl;
  }
  return 0;
}
