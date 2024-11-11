#include <bits/stdc++.h>
using namespace std;
class Petya_Square {
 private:
  int n, x, y;

 public:
  void input();
  void output(string res);
  void ans(int n, int x, int y);
};
void Petya_Square ::input() {
  cin >> n >> x >> y;
  ans(n, x, y);
}
void Petya_Square ::ans(int n, int x, int y) {
  ((x == n / 2 || x == n / 2 + 1) && (y == n / 2 || y == n / 2 + 1))
      ? output("NO")
      : output("YES");
}
void Petya_Square ::output(string res) { cout << res; }
int main() {
  Petya_Square p;
  p.input();
}
