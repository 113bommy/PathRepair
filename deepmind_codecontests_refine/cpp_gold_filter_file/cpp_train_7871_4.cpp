#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 233;
int v1 = 0, v2 = 0, v3 = 0;
int n;
int op[maxn], v[maxn];
int cal(int d, int x) {
  for (int i = 1; i <= n; i++) {
    int t = (v[i] >> d) & 1;
    if (op[i] == 0)
      x &= t;
    else if (op[i] == 1)
      x |= t;
    else
      x ^= t;
  }
  return x;
}
int main() {
  cin >> n;
  getchar();
  for (int i = 1; i <= n; i++) {
    char c = getchar();
    if (c == '&')
      op[i] = 0;
    else if (c == '|')
      op[i] = 1;
    else
      op[i] = 2;
    scanf("%d", &v[i]);
    getchar();
  }
  for (int i = 0; i < 10; i++) {
    if (cal(i, 0) == 0) {
      if (cal(i, 1) == 0) {
      } else {
        v2 |= (1 << i);
      }
    } else {
      if (cal(i, 1) == 0) {
        v2 |= (1 << i);
        v3 |= (1 << i);
      } else {
        v1 |= (1 << i);
        v2 |= (1 << i);
      }
    }
  }
  cout << 3 << endl;
  printf("| %d\n& %d\n^ %d\n", v1, v2, v3);
  return 0;
}
