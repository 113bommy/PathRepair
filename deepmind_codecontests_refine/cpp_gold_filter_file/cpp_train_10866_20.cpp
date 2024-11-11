#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int* pl = new int[n];
  int* nl = new int[n];
  int last, current;
  cin >> last;
  pl[0] = 0;
  nl[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> current;
    if (last <= current)
      pl[i] = pl[i - 1] + 1;
    else
      pl[i] = 0;
    if (last >= current)
      nl[i] = nl[i - 1] + 1;
    else
      nl[i] = 0;
    last = current;
  }
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    y -= nl[y - 1];
    if (x >= y - pl[y - 1])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
