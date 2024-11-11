#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 0, b = 0, c = 0, d = 0, res = INT_MAX;
  cin >> a >> b;
  cin >> c >> d;
  for (int i = 0; i <= 100; ++i)
    for (int j = 0; j <= 100; ++j) {
      if (b + i * a == d + j * c) res = min(res, (b + i * a));
    }
  cout << (res == INT_MAX ? -1 : res);
}
