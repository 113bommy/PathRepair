#include <bits/stdc++.h>
using namespace std;
struct nod {
  int pl, ind, sol;
};
int a[110000];
int n;
bool sor(nod x, nod y) {
  if (x.pl < y.pl) return true;
  if (x.pl > y.pl) return false;
  if (x.sol < y.sol) return true;
  if (x.sol > y.sol) return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  int x, y;
  bool done = false;
  int i;
  cin >> n;
  fill(a, a + 100002, -1);
  for (i = 0; i < n; ++i) {
    cin >> x >> y;
    if (x <= a[y]) continue;
    if (a[y] != x - 1)
      done = true;
    else
      a[y] = x;
  }
  if (done)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
