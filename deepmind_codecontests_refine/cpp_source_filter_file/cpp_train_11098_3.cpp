#include <bits/stdc++.h>
using namespace std;
int main() {
  char start, end;
  cin >> start >> end;
  int n;
  cin >> n;
  int mapa[100];
  mapa[0] = 'v';
  mapa[1] = '<';
  mapa[2] = '^';
  mapa[3] = '>';
  mapa['v'] = 0;
  mapa['<'] = 1;
  mapa['^'] = 2;
  mapa['>'] = 3;
  int ans = 0;
  if ((mapa[start] + n) % 4 == mapa[end]) ans++;
  if ((mapa[start] + 4 - (n % 4)) % 4 == mapa[end]) ans--;
  if (ans < 0) printf("ccw\n");
  if (ans > 0) printf("cw\n");
  if (!ans) printf("undefined\n");
  return 0;
}
