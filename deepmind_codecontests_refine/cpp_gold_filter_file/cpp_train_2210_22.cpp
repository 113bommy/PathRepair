#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n;
  vector<long long> pos(11, 0), neg(11, 0);
  for (int i = 0; i < n; i++) {
    cin >> v;
    if (v >= 0)
      pos[v]++;
    else
      neg[-v]++;
  }
  long long ways = (pos[0] * (pos[0] - 1)) / 2;
  for (int i = 1; i <= 10; i++) ways += pos[i] * neg[i];
  cout << ways << endl;
  return 0;
}
