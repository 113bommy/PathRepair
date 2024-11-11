#include <bits/stdc++.h>
using namespace std;
struct Node {
  int a, b, c;
} A[505], B[505];
const int INF = 2000000005;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &A[i].a, &A[i].b, &A[i].c);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &B[i].a, &B[i].b, &B[i].c);
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    int tmp = INF;
    int L = A[i].a * 2 + A[i].b * 2;
    int H = A[i].c;
    for (int j = 0; j < m; j++) {
      if (L % B[j].b != 0) {
        continue;
      }
      int cx = 0;
      int cy = B[j].b;
      int Left = B[j].a;
      int val = min(H, B[j].a);
      int cur = 0;
      int all = ceil(1.0 * H / val) * ceil(1.0 * L / B[j].b);
      while (true) {
        cur++;
        cx += val;
        Left -= val;
        if (Left < val || cur >= all) {
          break;
        }
        if (cx >= B[j].a || cx >= H) {
          cy += B[j].b;
          cx = 0;
        }
      }
      int t = ceil(1.0 * all / cur) * B[j].c;
      if (t < tmp) {
        tmp = t;
      }
    }
    ret += tmp;
  }
  cout << ret << endl;
}
