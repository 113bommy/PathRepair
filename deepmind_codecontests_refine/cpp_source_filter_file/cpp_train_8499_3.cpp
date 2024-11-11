#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 500005;
const long long OO = (long long)1 * 1e18;
int main() {
  string x;
  getline(cin, x);
  int v = 0;
  cout << "...\n";
  for (auto it : x) {
    while (v != (int)it) {
      v = (v - 1 + 256) % 256;
      cout << ".x.\n...\n";
    }
    cout << "xx.\n.x.\n...\n";
  }
  return 0;
}
