#include <bits/stdc++.h>
using namespace std;
int n, x;
int get_point(int p, int t) { return max(3 * p / 10, p - (p / 250) * t); }
int main() {
  ios::sync_with_stdio(false);
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    int a1 = get_point(a, c);
    int a2 = get_point(b, d);
    if (a1 == a2)
      cout << "Tie" << endl;
    else if (a1 < a2)
      cout << "Vasya" << endl;
    else
      cout << "Misha" << endl;
  }
}
