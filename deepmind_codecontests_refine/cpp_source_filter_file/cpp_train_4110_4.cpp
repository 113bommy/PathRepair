#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
void solve() {
  cin >> a >> b >> c >> d;
  a = max(3 * a / 10, a - (a * c / 250));
  b = max(3 * b / 10, b - (b * c / 250));
  if (a > b) cout << "Misha" << endl;
  if (b > a) cout << "Vasya" << endl;
  if (a == b) cout << "Tie" << endl;
}
int main() { solve(); }
