#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
struct Item {
  int val, id;
};
Item a[N];
bool operator<(const Item& x, const Item& y) { return x.val < y.val; }
int main() {
  int n, d, cnt, j, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i].val;
    a[i].id = i + 1;
  }
  if (n <= 3)
    cout << 1 << endl;
  else {
    sort(a, a + n);
    d = a[1].val - a[0].val;
    cnt = 0;
    for (i = 2; i < n; i++)
      if (a[i].val != a[0].val + 1LL * (i - cnt) * d) {
        cnt++;
        j = a[i].id;
      }
    if (cnt == 0)
      cout << 1 << endl;
    else if (cnt == 1)
      cout << j << endl;
    else {
      d = a[n - 1].val - a[n - 2].val;
      cnt = 0;
      for (i = n - 3; i >= 0; i--)
        if (a[i].val != a[n - 1].val - 1LL * (n - 1 - i + cnt) * d) {
          cnt++;
          j = a[i].id;
        }
      if (cnt == 1)
        cout << j << endl;
      else
        cout << -1 << endl;
    }
  }
  return 0;
}
