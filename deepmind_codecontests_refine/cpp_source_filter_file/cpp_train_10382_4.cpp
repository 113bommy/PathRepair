#include <bits/stdc++.h>
using namespace std;
using LD = long double;
using PLL = pair<long long, long long>;
using VII = vector<pair<int, int> >;
template <class T>
bool power_2(T v) {
  static_assert(std::is_integral<T>::value, "type should be integral");
  return v && !(v & (v - 1));
}
template <class T>
istream& operator>>(istream& st, vector<T>& container) {
  for (auto& u : container) st >> u;
  return st;
}
template <class T>
ostream& operator<<(ostream& st, const vector<T>& container) {
  for (auto& u : container) st << u << '\n';
  return st;
}
template <class T, size_t N>
istream& operator>>(istream& st, array<T, N>& container) {
  for (auto& u : container) st >> u;
  return st;
}
template <class T, size_t N>
ostream& operator<<(ostream& st, const array<T, N>& container) {
  for (auto u : container) st << u << ' ';
  return st;
}
template <class T, class U>
istream& operator>>(istream& st, pair<T, U>& p) {
  st >> p.first >> p.second;
  return st;
}
template <class T, class U>
ostream& operator<<(ostream& st, pair<T, U> p) {
  st << p.first << ' ' << p.second;
  return st;
}
template <class T, class U, class V>
pair<T, U> operator*(pair<T, U> p, V val) {
  return {p.first * val, p.second * val};
}
template <class T, class U, class V>
pair<T, U> operator/(pair<T, U> p, V val) {
  return {p.first / val, p.second / val};
}
template <class T, class U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return {a.first - b.first, a.second - b.second};
}
template <class T, class U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return {a.first + b.first, a.second + b.second};
}
template <class T>
T dotProduct(pair<T, T> a, pair<T, T> b) {
  return a.first * b.first + a.second * b.second;
}
template <class T>
T crossProduct(pair<T, T> a, pair<T, T> b) {
  return a.first * b.second - a.second * b.first;
}
template <class T>
T lengthPow(pair<T, T> a) {
  return a.first * a.first + a.second * a.second;
}
template <class T>
LD length(pair<T, T> a) {
  return sqrt(lengthPow(a));
}
int const inf = 1e9 + 7;
int const N = 1e5 + 7;
int const M = 1 << 3;
struct Node {
  priority_queue<int> rectangles;
  int max, min;
  Node() : max(-1), min(0) {}
};
bitset<N> seen, erased;
Node segTree[2 * M];
void update(int v) {
  auto& que = segTree[v].rectangles;
  int& minVal = segTree[v].min;
  int& maxVal = segTree[v].max;
  while (!que.empty() && erased[que.top()]) {
    que.pop();
  }
  int maxInChildren = -1;
  if (v < M) maxInChildren = max(segTree[v + v].max, segTree[v + v + 1].max);
  int minInChildren = 0;
  if (v < M) minInChildren = min(segTree[v + v].min, segTree[v + v + 1].min);
  int maxInNode = -1;
  if (!que.empty()) maxInNode = que.top();
  if (maxInNode > maxInChildren) {
    if (seen[maxInNode] || maxInNode < minInChildren)
      maxVal = -1;
    else
      maxVal = maxInNode;
  } else {
    maxVal = maxInChildren;
  }
  minVal = max(maxInNode, minInChildren);
}
void addSegment(int col, int a, int b, bool add, int v = 1, int l = 0,
                int p = M) {
  if (b <= l || p <= a) return;
  if (a <= l && p <= b) {
    if (add) {
      segTree[v].rectangles.push(col);
    }
    update(v);
    return;
  }
  int mid = (l + p) / 2;
  addSegment(col, a, b, add, 2 * v, l, mid);
  addSegment(col, a, b, add, 2 * v + 1, mid, p);
  update(v);
}
int x1[N], x2[N], Y1[N], Y2[N];
map<int, int> newCoordsX, newCoordsY;
vector<pair<int, int> > events[2 * N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x1[i] >> Y1[i] >> x2[i] >> Y2[i];
    newCoordsX[x1[i]] = 0;
    newCoordsX[x2[i]] = 0;
    newCoordsY[Y1[i]] = 0;
    newCoordsY[Y2[i]] = 0;
  }
  int j = 0;
  for (auto& u : newCoordsY) u.second = j++;
  j = 0;
  for (auto& u : newCoordsX) u.second = j++;
  for (int i = 0; i < n; ++i) {
    x1[i] = newCoordsX[x1[i]];
    x2[i] = newCoordsX[x2[i]];
    Y1[i] = newCoordsY[Y1[i]];
    Y2[i] = newCoordsY[Y2[i]];
    events[x1[i]].push_back({i, 1});
    events[x2[i]].push_back({i, 0});
  }
  for (int i = 0; i < 2 * n; ++i) {
    for (auto u : events[i]) {
      int c = u.first;
      int t = u.second;
      if (t == 0) erased[c] = 1;
      addSegment(c, Y1[c], Y2[c], t);
    }
    while (segTree[1].max >= segTree[1].min) {
      int id = segTree[1].max;
      seen[id] = 1;
      addSegment(id, Y1[id], Y2[id], 0);
    }
  }
  int res = 1;
  for (int i = 0; i < n; ++i) {
    if (seen[i]) ++res;
  }
  cout << res << '\n';
}
