#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int i1, i2, a1, a2;
  cout << "? ";
  for (int i = 1; i <= k; ++i) cout << i << ' ';
  cout << '\n';
  cout.flush();
  cin >> i1 >> a1;
  cout << "? ";
  for (int i = 1; i <= k + 1; ++i) {
    if (i == i1) ++i;
    cout << i << ' ';
  }
  cout << '\n';
  cout.flush();
  cin >> i2 >> a2;
  if (a1 < a2) {
    swap(i1, i2);
    swap(a1, a2);
  }
  int count = 0, c1 = 0, c2;
  for (int ch = 1; ch <= k + 10; ++ch) {
    if (ch == i1 || ch == i2) ++ch;
    if (ch == i1 || ch == i2) ++ch;
    ++c1;
    if (c1 > k - 1) break;
    cout << "? ";
    c2 = 0;
    for (int i = 1; i <= k + 10; ++i) {
      ++c2;
      if (c2 > k) break;
      if (i == i2) ++i;
      if (i == ch)
        cout << i2 << ' ';
      else
        cout << i << ' ';
    }
    cout << '\n';
    cout.flush();
    int ich, ach;
    cin >> ich >> ach;
    if (ich == i1) ++count;
  }
  cout << "! " << count + 1;
  cout.flush();
  return 0;
}
