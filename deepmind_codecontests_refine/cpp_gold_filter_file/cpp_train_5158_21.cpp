#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, count(0);
  cin >> n >> m;
  if (n > m) swap(n, m);
  for (int i(1); i <= n; i++) count += (m + i) / 5 - i / 5;
  cout << count << endl;
  return 0;
}
