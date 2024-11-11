#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, k;
set<int> good;
int main() {
  cin >> n >> k;
  cin >> a >> b >> c >> d;
  if (k < n + 1) {
    cout << "-1\n";
    exit(0);
  }
  if (n == 4) {
    cout << "-1\n";
    exit(0);
  }
  good.insert(a);
  good.insert(b);
  good.insert(c);
  good.insert(d);
  int t = 1;
  while (good.count(t)) ++t;
  good.insert(t);
  cout << a << " " << d << " " << t << " " << c;
  for (int i = 0; i < n; ++i)
    if (!good.count(i + 1)) cout << " " << i + 1;
  cout << " " << b << endl;
  cout << c;
  for (int i = 0; i < n; ++i)
    if (!good.count(i + 1)) cout << " " << i + 1;
  cout << " " << b << " " << a << " " << t << " " << d << endl;
}
