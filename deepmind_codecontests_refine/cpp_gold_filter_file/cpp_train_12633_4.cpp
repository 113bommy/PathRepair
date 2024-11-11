#include <bits/stdc++.h>
using namespace std;
double x[510], y[510];
int main(void) {
  int N, i;
  cin >> N;
  double theta = acos(-1.0) / 180.0;
  x[1] = 10.0 * cos(36.0 * theta);
  y[1] = 10.0 * sin(36.0 * theta);
  x[2] = 10.0 * cos(72.0 * theta);
  y[2] = -10.0 * sin(72.0 * theta);
  x[3] = x[2] + 10.0;
  y[3] = y[2];
  int V = 4 * N + 1;
  double d = x[1] * 2.0;
  for (i = 4; i < V; i++) {
    x[i] = x[i - 4] + d;
    y[i] = y[i - 4];
  }
  cout << V << endl;
  for ((i) = 0; (i) < (int)(V); (i)++) printf("%.12f %.12f\n", x[i], y[i]);
  for ((i) = 0; (i) < (int)(N); (i)++)
    printf("%d %d %d %d %d\n", 4 * i + 1, 4 * i + 2, 4 * i + 5, 4 * i + 4,
           4 * i + 3);
  vector<int> v;
  for ((i) = 0; (i) < (int)(N + 1); (i)++) v.push_back(4 * i);
  for (i = N - 1; i >= 0; i--) {
    v.push_back(4 * i + 2);
    v.push_back(4 * i + 1);
    v.push_back(4 * i + 3);
    v.push_back(4 * i);
  }
  for ((i) = 0; (i) < (int)(v.size()); (i)++) {
    cout << v[i] + 1;
    if (i + 1 != v.size()) cout << ' ';
  }
  cout << endl;
  return 0;
}
