#include <bits/stdc++.h>
using namespace std;
int movx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int movy[] = {0, 0, -1, 1, -1, 1, 1, -1};
int main() {
  string a;
  cin >> a;
  int x = a[0] - 'a';
  int y = a[1] - '0';
  int cont = 0;
  for (int i = 0; i < 8; ++i) {
    int aux = x + movx[i];
    int auy = y + movy[i];
    if (aux < 0 || auy < 0 || aux >= 8 || auy >= 8) continue;
    cont++;
  }
  printf("%d\n", cont);
  return 0;
}
