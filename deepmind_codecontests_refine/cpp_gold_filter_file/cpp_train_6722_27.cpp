#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, max1 = 1e9;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 1; i <= n; i++)
    if (n % i == 0 && i <= n / i)
      v.push_back(make_pair(i, n / i));
    else if (i > n / i)
      break;
  for (auto i : v)
    if (abs(i.first - i.second) < max1)
      a = i.first, b = i.second, max1 = abs(i.first - i.second);
  cout << a << ' ' << b << '\n';
}
