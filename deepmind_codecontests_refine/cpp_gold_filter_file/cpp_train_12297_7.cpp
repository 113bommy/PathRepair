#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long l, e, ans, x, y;
    cin >> l >> e;
    l--;
    x = l / 2;
    y = e / 2;
    if (l % 2 == 1) x -= l;
    if (e % 2 == 1) y -= e;
    v.push_back(y - x);
  }
  for (int i = 0; i < n; i++) cout << v[i] << endl;
  return 0;
}
