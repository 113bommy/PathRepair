#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(1000, 1000000);
  map<int, int> ma;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a, x;
    cin >> a >> x;
    if (x < v[a]) ma[a] = x, v[a] = x;
  }
  map<int, int>::iterator it;
  for (it = ma.begin(); it != ma.end(); it++) sum = sum + (it->second);
  if (sum > k)
    cout << k;
  else
    cout << sum;
  return 0;
}
