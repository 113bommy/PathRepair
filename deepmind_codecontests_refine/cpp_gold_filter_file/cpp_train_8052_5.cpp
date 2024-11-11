#include <bits/stdc++.h>
using namespace std;
int N, Start, down1, down2, up, a, b;
bool mark[102][7];
void check(int x, int y, int syc) {
  mark[syc][x] = mark[syc][y] = mark[syc][7 - x] = mark[syc][7 - y] = 1;
  if (7 - x == y || x == Start || y == Start) {
    cout << "NO";
    exit(0);
  }
  for (int i = 1; i <= 6; i++)
    if ((down1 == i && mark[syc][i]) || (down2 == i && mark[syc][i])) {
      cout << "NO";
      exit(0);
    }
  for (int i = 1; i <= 6; i++)
    if (!mark[syc][i]) up = i;
  down1 = (up != down1 ? up : 0);
  down2 = (7 - up != down1 ? 7 - up : 0);
}
int main() {
  cin >> N >> Start;
  down1 = 7 - Start;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    check(a, b, i);
  }
  cout << "YES";
}
