#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  cout << (n & 1 ? -1 : 1) * ((n + 1) >> 1);
  return 0;
}
