#include <bits/stdc++.h>
using namespace std;
const int INF_MAX = 0x7FFFFFFF;
const int INF_MIN = -(1 << 30);
const double eps = 1e-10;
const double pi = acos(-1.0);
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q) {
  while (!Q.empty()) Q.pop();
}
inline int random(int l, int r) { return rand() % (r - l + 1) + l; }
int dir_4[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int dir_8[8][2] = {{0, 1},  {-1, 1}, {-1, 0}, {-1, -1},
                   {0, -1}, {1, -1}, {1, 0},  {1, 1}};
struct Node {
  int id, v, a, b;
} nodes[110000];
bool cmp1(Node a, Node b) { return a.v < b.v; }
bool cmp2(Node a, Node b) { return a.id < b.id; }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nodes[i].v;
    nodes[i].id = i;
  }
  sort(nodes, nodes + n, cmp1);
  for (int i = 0; i < n; i++) {
    if (i < (n + 2) / 3) {
      nodes[i].a = i;
      nodes[i].b = nodes[i].v - i;
    } else if (i < (n + 2) / 3 * 2) {
      nodes[i].b = i;
      nodes[i].a = nodes[i].v - i;
    }
  }
  for (int j = (2 + n) / 3 * 2, cnt = (2 + n) / 3; j < n; j++, cnt--) {
    nodes[j].b = cnt;
    nodes[j].a = nodes[j].v - cnt;
  }
  cout << "YES" << endl;
  sort(nodes, nodes + n, cmp2);
  for (int i = 0; i < n; i++) {
    i == 0 ? cout << nodes[i].a : cout << " " << nodes[i].a;
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    i == 0 ? cout << nodes[i].b : cout << " " << nodes[i].b;
  }
  cout << endl;
}
