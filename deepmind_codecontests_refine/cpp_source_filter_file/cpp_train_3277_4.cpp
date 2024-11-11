#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
struct point {
 public:
  long long x, y;
  point(long long a, long long b) {
    x = a;
    y = b;
  }
  point() {}
  void setPoint(long long a, long long b) {
    x = a;
    y = b;
  }
  double dist(point p) { return sqrt(pow(x - p.x, 2.0) + pow(y - p.y, 2.0)); }
  long long dot(point A, point B) {
    point OA(A.x - x, A.y - y), OB(B.x - x, B.y - y);
    return (OA.x * OB.x + OA.y * OB.y);
  }
  long long cross(point A, point B) {
    point OA(A.x - x, A.y - y), OB(B.x - x, B.y - y);
    return (OA.x * OB.y - OA.y * OB.x);
  }
  bool operator<(const point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};
int main() {
  long long ans = 0;
  int X, Y;
  string str;
  cin >> str;
  Y = str.size();
  cin >> X;
  int val;
  vector<pair<int, int>> a;
  for (int i = 0; i < (X); i++) {
    cin >> val;
    a.push_back(make_pair(val - 1, 1));
    a.push_back(make_pair(Y - val, -1));
  }
  sort((a).begin(), (a).end());
  int start = 0, open = 0, stop = 0, dist, last = 1;
  for (int i = 0; i < (a.size() / 2); i++) {
    stop = a[i].first;
    dist = stop;
    if (last != a[i].second) {
      dist = stop - start + 1;
      dist = start + dist / 2;
      last = a[i].second;
    }
    for (int j = (start); j < (dist); j++) {
      if (open > 0) {
        if (open % 2) {
          str[j] ^= str[Y - 1 - j] ^= str[j] ^= str[Y - 1 - j];
        }
      }
    }
    i = start = stop;
    open += a[i].second;
  }
  cout << str << endl;
  return 0;
}
