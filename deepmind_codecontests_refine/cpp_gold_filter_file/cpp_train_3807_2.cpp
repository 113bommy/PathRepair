#include <bits/stdc++.h>
using namespace std;
int n, x, col, to = sqrt(sqrt(2e9)), nmax = sqrt(2e9);
bool a[50000];
vector<int> v;
bool check(int x) {
  int mx = sqrt(x);
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] <= mx) {
      if (x % v[i] == 0) return 0;
    } else
      break;
  }
  return 1;
}
int main() {
  cin >> n;
  for (int i = 2; i <= to; ++i) {
    x = ((i) * (i));
    for (; x <= nmax; x += i) a[x] = 1;
  }
  for (int i = 2; i <= nmax; ++i)
    if (!a[i]) v.push_back(i);
  if (check(n)) return cout << 1, 0;
  if (check(n - 2) || n % 2 == 0) return cout << 2, 0;
  cout << 3;
  return 0;
}
