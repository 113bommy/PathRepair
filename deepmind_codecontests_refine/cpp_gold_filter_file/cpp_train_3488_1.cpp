#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
unordered_set<int> dict;
int main() {
  long long a, b, x;
  cin >> x >> a >> b;
  if (a % x != 0) {
    a += x - (a % x + x) % x;
  }
  if (a > b) {
    cout << 0 << endl;
  } else {
    cout << (b - a + x) / x << endl;
  }
  return 0;
}
