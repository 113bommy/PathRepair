#include <bits/stdc++.h>
using namespace std;
struct PT {
  int x, y;
  PT() {}
  PT(int x, int y) : x(x), y(y) {}
  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator*(int c) const { return PT(x * c, y * c); }
  PT operator/(int c) const { return PT(x / c, y / c); }
};
int main() {
  long long int N, J;
  cin >> N >> J;
  PT m;
  cin >> m.x >> m.y;
  vector<PT> pts(N);
  for (int i = 0; i < N; i++) cin >> pts[i].x >> pts[i].y;
  J %= (2 * N);
  for (int i = 0; i < min(J, N); i++) m = pts[i] * 2 - m;
  for (int i = N; i < J; i++) m = pts[i - N] * 2 - m;
  cout << m.x << " " << m.y << endl;
  return 0;
}
