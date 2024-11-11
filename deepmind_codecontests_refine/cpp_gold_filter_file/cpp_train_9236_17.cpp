#include <bits/stdc++.h>
using namespace std;
struct NODE {
  int x, y, id;
} node[105];
int main() {
  double n, vb, vs, tmp, ex, ey;
  int resid = 2;
  double d[105];
  cin >> n >> vb >> vs >> tmp;
  for (int i = 0; i < n - 1; ++i) {
    cin >> node[i].x;
    node[i].y = 0;
    node[i].id = i + 2;
  }
  cin >> ex >> ey;
  if (vs > vb) {
    cout << "2" << endl;
    return 0;
  }
  double t = 10000006;
  for (int i = 0; i < n - 1; ++i) {
    d[i] = sqrt((ex - node[i].x) * (ex - node[i].x) + (ey - 0) * (ey - 0));
    if (t >= (d[i] / vs + node[i].x / vb)) {
      t = d[i] / vs + node[i].x / vb;
      resid = node[i].id;
    }
  }
  cout << resid << endl;
  return 0;
}
