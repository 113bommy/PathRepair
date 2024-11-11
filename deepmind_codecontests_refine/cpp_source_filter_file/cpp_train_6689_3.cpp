#include <bits/stdc++.h>
using namespace std;
int f_win(int64_t s, int64_t e) {
  if (e - s < 2 || (e & 1) || s > (e / 4) * 2) return ((e - s) & 1);
  if (s <= e / 4) return f_win(s, e / 4);
  return 1;
}
int f_lose(int64_t s, int64_t e) {
  if (s * 2 > e) return 1;
  return f_win(s, e / 2 + 2);
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int f = 1, s = 0;
  for (int i = 0; f != s && i < n; i++) {
    int64_t x, y;
    cin >> x >> y;
    f = f_lose(x, y) ^ s;
    s = f_win(x, y) ^ s;
  }
  cout << s << ' ' << f << '\n';
}
