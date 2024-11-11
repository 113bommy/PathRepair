#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 1;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    if (a + i < n)
      a = a + i;
    else
      a = a + i - n;
    cout << a << " ";
  }
  return 0;
}
