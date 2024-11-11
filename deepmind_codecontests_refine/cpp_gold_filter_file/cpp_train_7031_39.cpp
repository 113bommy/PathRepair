#include <bits/stdc++.h>
using namespace std;
int main() {
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int x = min(min(p1, p2), min(p3, p4));
  int res = 0;
  for (int i = a; i < b + 1; i++)
    if (i < x) res++;
  cout << res << endl;
}
