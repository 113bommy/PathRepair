#include <bits/stdc++.h>
using namespace std;
int trans(int x) {
  int res = 0;
  for (int i = 0; i < 8; ++i) {
    res = 2 * res + x % 2;
    x /= 2;
  }
  return res;
}
int main() {
  char s[100];
  cin.getline(s, 100);
  int prev = 0;
  for (size_t i = 0; i < strlen(s); ++i) {
    int p;
    if (i == 0) {
      p = 0;
    } else {
      p = (int)s[i - 1];
    }
    int q = (int)s[i];
    cout << (trans(p) - trans(q) + 256) % 256 << '\n';
  }
  return 0;
}
