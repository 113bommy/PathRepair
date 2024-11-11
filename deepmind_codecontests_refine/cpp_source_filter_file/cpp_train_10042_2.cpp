#include <bits/stdc++.h>
using namespace std;
int res;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 25; ++i) {
    res += i;
    if (n == res)
      return cout << "YES", 0;
    else if (n > res)
      return cout << "NO", 0;
  }
  return 0;
}
