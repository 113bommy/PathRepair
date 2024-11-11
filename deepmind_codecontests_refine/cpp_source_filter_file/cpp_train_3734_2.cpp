#include <bits/stdc++.h>
using namespace std;
int main() {
  string w;
  cin >> w;
  bool f[256] = {};
  for (char c : w) {
    f[c] ^= 1;
  }
  bool ans = 0;
  for (int i = 0; i < 256; i++) ans ^= f[i];
  cout << (ans ? "No" : "Yes") << endl;
}
