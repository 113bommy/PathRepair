#include <bits/stdc++.h>
using namespace std;
void first() {
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  if (b == m || a == n)
    cout << abs(n - a) + abs(m - b) << endl;
  else
    cout << abs(n - 1) + abs(m - b) + 2 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) first();
}
