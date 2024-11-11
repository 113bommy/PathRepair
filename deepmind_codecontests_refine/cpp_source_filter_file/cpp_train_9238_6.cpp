#include <bits/stdc++.h>
using namespace std;
void len(double& d, int v, int x, int y, int vb, int vs) {
  double time = (double)v / (double)vb;
  time += sqrt((double)(x - v) * (double)(x - v) + (double)y * y) / (double)vs;
  d = time;
}
int main() {
  int x, y;
  int n, vb, vs;
  cin >> n >> vb >> vs;
  vector<int> v(n);
  vector<double> d(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  cin >> x >> y;
  for (int i = 0; i < n; i++) len(d[i], v[i], x, y, vb, vs);
  int imin;
  double min = 2000000;
  for (int i = 1; i < n; i++)
    if (d[i] < min) {
      imin = i;
      min = d[i];
    }
  cout << imin + 1 << endl;
  return 0;
}
