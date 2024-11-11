#include <bits/stdc++.h>
using namespace std;
int xhid[4] = {-1, -1, 1, 1};
int yhid[4] = {1, -1, 1, -1};
int nhid = 4;
double aabs(double x) { return x > 0 ? x : -x; }
double getc(int i, int j, int k) {
  return (xhid[j] - xhid[i]) * (yhid[k] - yhid[i]) -
         (xhid[k] - xhid[i]) * (yhid[j] - yhid[i]);
}
double get1(int i, int j, int k) { return aabs(getc(i, j, k)); }
double get2(int i, int j, int k) { return getc(i, j, k) > 0 ? 1 : -1; }
int main() {
  int n;
  cin >> n;
  vector<double> x(n), y(n);
  x[0] = x[1] = 0;
  for (int i = 2; i < n; ++i) {
    double tmp1, tmp2;
    cout << "1 1 " << i + 1 << " 2" << endl;
    cin >> tmp1;
    cout << "2 1 " << i + 1 << " 2" << endl;
    cin >> tmp2;
    x[i] = tmp1 * tmp2;
  }
  double smallest = aabs(x[2]);
  int id = 2;
  for (int i = 2; i < n; ++i) {
    if (aabs(x[i]) < smallest) {
      smallest = aabs(x[i]);
      id = i;
    }
  }
  double samesidesign = 0, diffsidesign = 0;
  y[id] = 0;
  y[0] = 0;
  for (int i = 1; i < n; ++i) {
    if (i == id) continue;
    cout << "1 1 " << i + 1 << " " << id + 1 << endl;
    cin >> y[i];
    if (x[i] * x[id] > 0) {
      if (samesidesign == 0) {
        cout << "2 1 " << i + 1 << " " << id + 1 << endl;
        cin >> samesidesign;
      }
      y[i] *= samesidesign;
    } else {
      if (diffsidesign == 0) {
        cout << "2 1 " << i + 1 << " " << id + 1 << endl;
        cin >> diffsidesign;
      }
      y[i] *= diffsidesign;
    }
  }
  vector<pair<pair<double, double>, int> > xsort(0);
  for (int i = 0; i < n; ++i) {
    xsort.push_back(make_pair(make_pair(x[i], y[i]), i));
  }
  sort(xsort.begin(), xsort.end());
  vector<int> fjant(0);
  for (int i = 0; i < n; ++i) {
    int pt = xsort[i].second;
    int x0 = xsort[0].second, x1 = xsort[n - 1].second;
    if (y[pt] <= y[x0] + (x[pt] - x[x0]) * (y[x1] - y[x0]) / (x[x1] - x[x0])) {
      fjant.push_back(pt + 1);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    int pt = xsort[i].second;
    int x0 = xsort[0].second, x1 = xsort[n - 1].second;
    if (y[pt] > y[x0] + (x[pt] - x[x0]) * (y[x1] - y[x0]) / (x[x1] - x[x0])) {
      fjant.push_back(pt + 1);
    }
  }
  cout << 0;
  int q = 0;
  for (q = 0; q < n; ++q)
    if (fjant[q] == 1) break;
  if (x[id] > 0)
    for (int i = 0; i < n; ++i) cout << " " << fjant[(n + q - i) % n];
  else
    for (int i = 0; i < n; ++i) cout << " " << fjant[(n + q + i) % n];
  cout << endl;
}
