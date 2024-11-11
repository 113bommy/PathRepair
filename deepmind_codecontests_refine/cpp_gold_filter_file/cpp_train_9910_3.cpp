#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1e9 + 7;
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T> v) {
  os << "(" << v.first << ", " << v.second << ")";
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) {
      os << " ";
    }
    os << v[i];
  }
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<vector<T>> v) {
  for (int i = 0; i < v.size(); i++) {
    if (i > 0) {
      os << endl;
    }
    os << v[i];
  }
  return os;
}
struct point {
  long long id, x, y, z;
  bool operator<(const point& right) const {
    if (x == right.x) {
      if (y == right.y) {
        return z < right.z;
      } else {
        return y < right.y;
      }
    } else {
      return x < right.x;
    }
  }
};
long long dist(point& p1, point& p2) {
  long long dx = abs(p1.x - p2.x);
  long long dy = abs(p1.y - p2.y);
  long long dz = abs(p1.z - p2.z);
  return dx + dy + dz;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<point> P;
  vector<point> Q;
  vector<point> R;
  for (int i = 0; i < (int)n; ++i) {
    long long x, y, z;
    cin >> x >> y >> z;
    point p = {i, x, y, z};
    P.push_back(p);
  }
  sort(P.begin(), P.end());
  for (int i = 0; i < (int)n; ++i) {
    int j = i;
    while (j < n && P[i].x == P[j].x && P[i].y == P[j].y) j++;
    int len = j - i;
    for (int k = 0; k < (int)len / 2; ++k) {
      cout << P[i + 2 * k].id + 1 << " " << P[i + 2 * k + 1].id + 1 << endl;
    }
    if (len % 2 == 1) Q.push_back(P[i + len - 1]);
    i = j - 1;
  }
  sort(Q.begin(), Q.end());
  long long m = Q.size();
  for (int i = 0; i < (int)m; ++i) {
    int j = i;
    while (j < m && Q[i].x == Q[j].x) j++;
    int len = j - i;
    for (int k = 0; k < (int)len / 2; ++k) {
      cout << Q[i + 2 * k].id + 1 << " " << Q[i + 2 * k + 1].id + 1 << endl;
    }
    if (len % 2 == 1) R.push_back(Q[i + len - 1]);
    i = j - 1;
  }
  for (int i = 0; i < (int)R.size() / 2; ++i) {
    cout << R[2 * i].id + 1 << " " << R[2 * i + 1].id + 1 << endl;
  }
  return 0;
}
