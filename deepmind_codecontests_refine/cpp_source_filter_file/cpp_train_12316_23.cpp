#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l, m, n, d, a = 0;
  cin >> k >> l >> m >> n >> d;
  for (int i = 1; i < d; i++)
    if (i % k && i % l && i % m && i % n) a++;
  cout << d - a << endl;
  return 0;
}
