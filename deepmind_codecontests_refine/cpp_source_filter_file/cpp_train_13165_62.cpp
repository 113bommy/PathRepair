#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1111;
const int INF = 0x7f7f7f7f;
int cases;
int num[11];
int main() {
  num[0] = 2, num[1] = 7, num[2] = 2, num[3] = 3, num[4] = 3, num[5] = 3,
  num[6] = 2, num[7] = 5, num[8] = 1, num[9] = 2;
  int x, y;
  scanf("%1d%1d", &x, &y);
  cout << num[x] * num[y] << endl;
}
