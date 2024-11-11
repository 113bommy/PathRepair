#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int n, d;
bool q[810][810][2][2], use[810][810][2][2];
pair<int, int> m[110];
int c = 401;
bool calc(int x, int y, bool q1, bool q2) {
  if (use[x + c][y + c][q1][q2]) return q[x + c][y + c][q1][q2];
  use[x + c][y + c][q1][q2] = true;
  if (x * x + y * y > d * d) {
    q[x + c][y + c][q1][q2] = true;
    return true;
  }
  bool q12 = false;
  for (int i = 0; i < n; i++)
    q12 |= !calc(x + m[i].first, y + m[i].second, q2, q1);
  if (!q1) q12 |= !calc(2 * x - y, x, q2, 1);
  q[x + c][y + c][q1][q2] = q12;
  return q12;
}
int main() {
  int x, y;
  cin >> x >> y >> n >> d;
  for (int i = 0; i < n; i++) scanf("%d %d", &m[i].first, &m[i].second);
  bool q1 = calc(x, y, 0, 0);
  if (q1)
    printf("Anton\n");
  else
    printf("Dasha\n");
  return 0;
}
