#include <bits/stdc++.h>
using namespace std;
int a;
string b;
inline bool check(int a) {
  string t;
  while (a) {
    if (a % 10 == 4) {
      t += '4';
    } else if (a % 10 == 7) {
      t += '7';
    }
    a /= 10;
  }
  reverse(t.begin(), t.end());
  return t == b;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin >> a >> b;
  for (int i = a + 1;; ++i) {
    if (check(i)) {
      cout << i;
      break;
    }
  }
}
