#include <bits/stdc++.h>
using namespace std;
int main() {
  int test = 0;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    int len = to_string(n).length();
    cout << 10 * (n % 10 - 1) + len * (len + 1) / 2;
  }
}
