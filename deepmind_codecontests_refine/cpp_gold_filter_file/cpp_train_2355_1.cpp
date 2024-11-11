#include <bits/stdc++.h>
using namespace std;
vector<int> vi;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n, x, a;
  cin >> n >> x;
  a = (n - 1);
  a -= a % 4;
  n -= a;
  if (!x && n == 2 && a >= 4) a -= 4, n += 4;
  if (n == 2 && x == 0) return cout << "NO\n", 0;
  cout << "YES\n";
  for (int i = 1000000 - 1, cnt = 0; cnt < a; cnt++, i--) {
    cout << i << ' ';
  }
  if (n == 6) {
    cout << 10 << ' ' << 5 << ' ' << 15 << ' ' << 14 << ' ' << 6 << ' ' << 8
         << endl;
    return 0;
  }
  for (int i = 0; i < 18; i++)
    if ((x & (1 << i)) == 0) vi.push_back(i);
  assert(vi.size() > 1 || ((1 << vi[0]) | (1 << vi[1]) | x) <= 900001);
  if (n == 1)
    cout << x << endl;
  else if (n == 2) {
    cout << (x | (1 << vi[0])) << ' ' << (1 << vi[0]) << endl;
  } else if (n == 3) {
    cout << (x | (1 << vi[0])) << ' ' << ((1 << vi[0]) | (1 << vi[1])) << ' '
         << (1 << vi[1]) << endl;
  } else if (n == 4) {
    cout << x << ' ' << (x | (1 << vi[0])) << ' '
         << (x | (1 << vi[1]) | (1 << vi[0])) << ' ' << (1 << vi[1]) << endl;
  }
  return 0;
}
