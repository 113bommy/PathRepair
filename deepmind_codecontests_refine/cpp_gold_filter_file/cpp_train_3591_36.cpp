#include <bits/stdc++.h>
using namespace std;
long max(long a, long b) { return a > b ? a : b; }
int main() {
  long m, n;
  cin >> n >> m;
  long a = max(m - 1, 1);
  if (m <= n / 2) a = m + 1;
  cout << a << endl;
}
