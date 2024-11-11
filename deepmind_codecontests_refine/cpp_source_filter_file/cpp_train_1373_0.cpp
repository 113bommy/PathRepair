#include <bits/stdc++.h>
const int INF = 1000000009;
const int MAXN = 100001;
const int MOD = 1000000007;
const double PI = 3.14159265359;
const double EPS = 1e-6;
using namespace std;
int maxv = -INF;
int n, m, k, cnt;
struct TPaper {
  int x1, y1;
  int x2, y2;
} a[3];
bool comp(TPaper p1, TPaper p2) {
  if (p1.x1 != p2.x1) return p1.x1 < p2.x1;
  return p1.x2 < p2.x2;
};
void swap(TPaper &p1, TPaper &p2) {
  swap(p1.x1, p2.x1);
  swap(p1.y1, p2.y1);
  swap(p1.x2, p2.x2);
  swap(p1.y2, p2.y2);
  return;
};
int main() {
  for (int i = 0; i < 3; i++) {
    cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
  }
  if (a[1].x1 > a[2].x1) swap(a[1], a[2]);
  int x1 = a[0].x1, x2 = a[0].x2;
  int y1 = a[0].y1, y2 = a[0].y2;
  if (x1 >= a[1].x1 && y1 >= a[1].y1 && x2 <= a[1].x2 && y2 <= a[1].y2) {
    cout << "NO\n";
    return 0;
  }
  if (x1 >= a[2].x1 && y1 >= a[2].y1 && x2 <= a[2].x2 && y2 <= a[2].y2) {
    cout << "NO\n";
    return 0;
  }
  if (x1 < min(a[1].x1, a[2].x1) || x2 > max(a[1].x2, a[2].x2)) {
    cout << "YES\n";
    return 0;
  }
  if (a[1].x2 < a[2].x1 && x2 > a[1].x2) {
    cout << "YES\n";
    return 0;
  }
  if (a[1].y1 > a[2].y1) swap(a[1], a[2]);
  if (y1 < min(a[1].y1, a[2].y1) || y2 > max(a[1].y2, a[2].y2)) {
    cout << "YES\n";
    return 0;
  }
  if (a[1].y2 < a[2].y1 && y2 > a[1].y2) {
    cout << "YES\n";
    return 0;
  }
  if (x1 < max(a[1].x1, a[2].x1) && y2 > min(a[1].y2, a[2].y2)) {
    cout << "YES\n";
    return 0;
  }
  if (x2 > min(a[1].x2, a[2].x2) && y2 > min(a[1].y2, a[2].y2)) {
    cout << "YES2\n";
    return 0;
  }
  if (x2 > min(a[1].x2, a[2].x2) && y1 < max(a[1].y1, a[2].y1)) {
    cout << "YES\n";
    return 0;
  }
  if (x1 < max(a[1].x1, a[2].x1) && y1 < max(a[1].y1, a[2].y1)) {
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
};
