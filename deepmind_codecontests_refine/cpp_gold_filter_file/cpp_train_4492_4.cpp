#include <bits/stdc++.h>
using namespace std;
void no() {
  cout << -1;
  exit(0);
}
int main() {
  int n;
  cin >> n;
  long long x, y;
  cin >> x >> y;
  long long tmp = y - n + 1;
  if (tmp <= 0) no();
  long long m = tmp * tmp;
  if (m + n - 1 < x) no();
  for (int i = 0; i < (n - 1); i++) cout << 1 << endl;
  cout << tmp << endl;
  return 0;
}
