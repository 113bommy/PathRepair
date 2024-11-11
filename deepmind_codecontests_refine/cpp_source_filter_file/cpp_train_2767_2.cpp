#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;
int a[5], n;
void check() {
  for (int i = 0; i < n; i++)
    if (i % 2)
      swap(a[1], a[2]);
    else
      swap(a[0], a[1]);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x;
  cin >> n >> x;
  n %= 6;
  a[0] = 1;
  check();
  if (a[x] == 1) return cout << 0 << endl, 0;
  a[0] = a[1] = a[2];
  a[1] = 1;
  check();
  if (a[x]) return cout << 1 << endl, 0;
  cout << 2 << endl;
}
