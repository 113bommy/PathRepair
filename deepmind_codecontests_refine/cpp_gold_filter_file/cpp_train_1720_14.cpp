#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, d = 1;
  cin >> n;
  while (n > d) {
    n -= d;
    d++;
  }
  cout << n;
  return 0;
}
