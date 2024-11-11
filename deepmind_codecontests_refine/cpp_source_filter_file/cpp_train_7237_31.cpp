#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  while (cin >> n >> a) {
    if (a & 1 == 0) a = n + 1 - a;
    int ans = (a + 1) / 2;
    cout << a << endl;
  }
  return 0;
}
