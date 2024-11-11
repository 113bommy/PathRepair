#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n, c = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a, c += i * (a - 1) + a;
  cout << c << endl;
  return 0;
}
