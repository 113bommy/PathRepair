#include <bits/stdc++.h>
using namespace std;
struct taz {
  int x, y;
};
int main() {
  int n, m, B;
  cin >> n >> m >> B;
  taz a[n + 1], b[m + 1];
  int N, IND, CL;
  for (int i = 1; i <= n; i++) {
    a[i].y = 0;
    b[i].x = 0;
  }
  for (int i = 1; i <= m; i++) {
    b[i].y = 0;
    b[i].x = 0;
  }
  for (int i = 1; i <= B; i++) {
    cin >> N >> IND >> CL;
    if (N == 1) {
      for (int I = 1; I <= m; I++) {
        a[IND].x = CL;
        a[IND].y = i;
      }
    } else {
      for (int I = 1; I <= n; I++) {
        b[IND].x = CL;
        b[IND].y = i;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i].y > b[j].y)
        cout << a[i].x << ' ';
      else
        cout << b[j].x << ' ';
    }
    cout << endl;
  }
  return 0;
}
