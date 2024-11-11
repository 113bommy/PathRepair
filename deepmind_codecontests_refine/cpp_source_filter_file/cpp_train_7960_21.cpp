#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string a, x,
      fn[10] = {"1", "1", "2", "3", "223", "5", "35", "7", "2227", "9"};
  cin >> n >> a;
  for (int i = 0; i < n; i++)
    if (a[i] > '1') x += fn[a[i] - '0'];
  sort(x.rbegin(), x.rend());
  cout << x << endl;
  return 0;
}
