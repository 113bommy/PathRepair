#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<complex<double> > p1;
vector<complex<double> > p2;
bool vis[20005];
double cross(complex<double> a, complex<double> b) {
  return (conj(a) * b).imag();
}
bool valid(complex<double> a) {
  if (cross(p1[1] - p1[0], a - p1[0]) != 0 &&
      cross(p1[n - 1] - p1[0], a - p1[0]) != 0)
    return 1;
  return 0;
}
int main() {
  cin >> n;
  complex<double> a;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (i == 0) a = complex<double>(x, y);
    p1.push_back(complex<double>(x, y));
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    p2.push_back(complex<double>(x, y));
  }
  for (int i = 0; i < p2.size(); i++) {
    complex<double> c = p2[i];
    int lo = 2, hi = n - 1, mid;
    if (!valid(c)) break;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (cross(p1[mid - 1] - a, c - a) <= 0 &&
          cross(p1[mid] - p1[mid - 1], c - p1[mid - 1]) < 0 &&
          cross(a - p1[mid], c - p1[mid]) <= 0) {
        vis[i] = 1;
        break;
      } else if ((cross(p1[mid] - a, c - a)) < 0)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
  }
  for (int i = 0; i < p2.size(); i++) {
    if (!vis[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
