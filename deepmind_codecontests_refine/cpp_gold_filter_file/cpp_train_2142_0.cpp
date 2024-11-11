#include <bits/stdc++.h>
using namespace std;
string p[2] = {"G", "B"};
bool mark = 0;
inline void prnt(int x, int y) {
  for (int i = 0; i < x; i++) cout << p[1 - mark] << p[mark];
  if (y > x) cout << p[1 - mark];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, a, b;
  cin >> n >> k >> a >> b;
  if (a > b) {
    swap(a, b);
    mark = 1 - mark;
  }
  if (b > k * (a + 1)) return cout << "NO", 0;
  while (b >= a) {
    if (a == b || b == a + 1) return prnt(a, b), 0;
    int t = min(k, b - a);
    for (int i = 0; i < t; i++) cout << p[1 - mark];
    if (a) cout << p[mark], a--;
    b -= t;
  }
}
