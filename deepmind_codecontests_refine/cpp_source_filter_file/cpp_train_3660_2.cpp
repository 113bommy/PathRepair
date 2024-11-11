#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
struct point {
  int x, y, pos;
  point(int _x, int _y) {
    x = _x;
    y = _y;
  }
  int operator*(const point &other) const {
    long long temp = 1LL * x * other.y - y * other.x;
    if (temp == 0) return temp;
    return temp / abs(temp);
  }
  point operator-(const point &other) const {
    return point(x - other.x, y - other.y);
  }
  bool operator<(const point &other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
};
vector<point> points;
bool taken[MAXN];
int arr[MAXN];
vector<int> order;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  point mx = point(1e9 + 5, 1e9 + 5);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    point temp = point(a, b);
    temp.pos = i;
    points.push_back(temp);
    mx = min(mx, temp);
  }
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) arr[i] = (s[i] == 'L') ? 1 : -1;
  taken[mx.pos] = true;
  order.push_back(mx.pos);
  point MX = point(0, 0);
  int pos = 0;
  for (; pos < n; pos++) {
    if (!taken[pos]) {
      MX = points[pos];
      break;
    }
  }
  ++pos;
  for (; pos < n; pos++)
    if (!taken[pos] && (MX - mx) * (points[pos] - MX) != arr[0])
      MX = points[pos];
  taken[MX.pos] = true;
  order.push_back(MX.pos);
  mx = MX;
  for (int i = 1; i < s.size(); i++) {
    pos = 0;
    for (; pos < n; pos++) {
      if (!taken[pos]) {
        MX = points[pos];
        break;
      }
    }
    ++pos;
    for (; pos < n; pos++)
      if (!taken[pos] && (MX - mx) * (points[pos] - MX) != arr[i])
        MX = points[pos];
    taken[MX.pos] = true;
    order.push_back(MX.pos);
    mx = MX;
  }
  for (int i = 0; i < n; i++)
    if (!taken[i]) order.push_back(points[i].pos);
  for (int i = 0; i < order.size(); i++) cout << order[i] + 1 << " ";
  return 0;
}
