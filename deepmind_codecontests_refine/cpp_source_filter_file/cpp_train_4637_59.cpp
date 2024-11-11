#include <bits/stdc++.h>
using namespace std;
double dist(double x, double y, double z, double x1, double y1, double z1) {
  return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1));
}
int main() {
  int n;
  cin >> n;
  double eps = 1e-8;
  pair<double, pair<double, double> > arr[n];
  double x, y, z;
  int pos = -1;
  for (int i = 0; i <= n; i++) {
    cin >> x >> y >> z;
    arr[i] = make_pair(x, make_pair(y, z));
  }
  double vs, vharrypotter;
  cin >> vharrypotter >> vs;
  double startx, starty, startz;
  cin >> startx >> starty >> startz;
  double totalt = 0, segmentt = 0, htime = 0, reqt = 0;
  double leftt = 0, rightt = 0;
  for (int i = 1; i <= n; i++) {
    segmentt = dist(arr[i - 1].first, arr[i - 1].second.first,
                    arr[i - 1].second.second, arr[i].first, arr[i].second.first,
                    arr[i].second.second) /
               vs;
    htime = dist(startx, starty, startz, arr[i].first, arr[i].second.first,
                 arr[i].second.second) /
            (vharrypotter * 1.0);
    totalt += segmentt;
    if (htime <= totalt + eps) {
      leftt = totalt - segmentt;
      pos = i;
      break;
    }
  }
  if (pos != -1) {
    int iter = 200;
    double outx = 0, outy = 0, outz = 0, outt = 0;
    double leftx = arr[pos - 1].first;
    double lefty = arr[pos - 1].second.first;
    double leftz = arr[pos - 1].second.second;
    double rightx = arr[pos].first;
    double righty = arr[pos].second.first;
    double rightz = arr[pos].second.second;
    while (iter--) {
      double midx = (leftx + rightx) / 2;
      double midy = (lefty + righty) / 2;
      double midz = (leftz + rightz) / 2;
      htime = dist(startx, starty, startz, midx, midy, midz) / vharrypotter;
      double mid = leftt + dist(leftx, lefty, leftz, midx, midy, midz) / vs;
      if (htime <= mid + eps) {
        outt = mid;
        outx = midx;
        outy = midy;
        outz = midz;
        rightx = midx;
        righty = midy;
        rightz = midz;
        rightt = mid;
      } else {
        leftx = midx;
        lefty = midy;
        leftz = midz;
        leftt = mid;
      }
    }
    cout << setprecision(10) << fixed;
    cout << "YES\n";
    cout << outt << endl;
    cout << outx << " " << outy << " " << outz << endl;
  } else
    cout << "NO\n";
  return 0;
}
