#include <bits/stdc++.h>
using namespace std;
int n, m, Start, End, x00, y00, x11, y11;
void Read() {
  int i;
  scanf("%d%d%d%d", &n, &m, &Start, &End);
  Start--;
  End--;
  x00 = Start / m;
  y00 = Start % m;
  x11 = End / m;
  y11 = End % m;
  return;
}
int Answer() {
  if (m == 1 || n == 1) return 1;
  if (x00 == x11) return 1;
  if (y00 == 0 && y11 == m - 1) return 1;
  if (y00 == y11 + 1) return 2;
  if (Start == 0 && End == n - 1) return 1;
  if (End == n - 1) return 2;
  if (abs(x00 - x11) == 1) return 2;
  if (y00 == 0 || y11 == m - 1) return 2;
  return 3;
}
int main() {
  Read();
  printf("%d\n", Answer());
  return 0;
}
