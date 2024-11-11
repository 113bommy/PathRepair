#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 1;
int n;
int main() {
  cin >> n;
  if (n > 4) {
    for (int i = 1; i <= n; i++) {
      if (i % 4 == 1) cout << "a";
      if (i % 4 == 2) cout << "b";
      if (i % 4 == 3) cout << "c";
      if (i % 4 == 0) cout << "d";
    }
  } else {
    for (char i = 'a';; i++) {
      n--;
      cout << i;
      if (n == 0) break;
    }
  }
}
