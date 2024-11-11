#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
double PI = 3.1415926535897932384626433832795;
const long long oo = (long long)1e9 + 1;
const double eps = 1e-9;
const long long mod = 1000000009;
int x[2], y[2], a, b;
bool Check() {
  for (int i = 1; i < a; i++)
    for (int j = 1; j < a; j++)
      if (j * j + i * i == a * a) {
        x[0] = j, y[0] = i;
        x[1] = -i * b / a, y[1] = j * b / a;
        if (x[1] * x[1] + y[1] * y[1] == b * b && y[0] != y[1]) return true;
      }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d%d", &a, &b);
  if (Check()) {
    printf("YES\n0 0\n");
    printf("%d %d\n%d %d\n", x[0], y[0], x[1], y[1]);
  } else {
    printf("NO\n");
  }
}
