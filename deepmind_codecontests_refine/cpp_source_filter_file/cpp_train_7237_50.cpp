#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
int n, a;
int main() {
  cin >> n >> a;
  if (a % 2 == 1)
    cout << (a + 1) / 2;
  else
    cout << n - 3 - (a / 2);
  return 0;
}
