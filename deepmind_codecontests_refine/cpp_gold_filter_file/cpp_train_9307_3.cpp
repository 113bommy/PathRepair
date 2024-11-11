#include <bits/stdc++.h>
using namespace std;
int Max(int a, int b) { return (((b - a) >> (32 - 1)) & (a ^ b)) ^ b; }
int Min(int a, int b) { return (((b - a) >> (32 - 1)) & (a ^ b)) ^ a; }
long long GCD(long long a, long long b) { return b != 0 ? GCD(b, a % b) : a; }
long long LCM(long long a, long long b) { return a * (b / GCD(a, b)); }
long long Pow(long long n, long long e) {
  if (e == 0) return 1;
  if (e == 1)
    return n;
  else if (e & 1) {
    long long t = Pow(n, e / 2);
    return n * t * t;
  } else {
    long long t = Pow(n, e / 2);
    return t * t;
  }
}
struct Line {
  int A, B, C;
  Line() {}
  Line(int x1, int y1, int x2, int y2) {
    A = -(y1 - y2);
    B = (x1 - x2);
    C = -(A * x1 + B * y1);
    int gcd = abs(GCD(A, GCD(B, C)));
    if (gcd != 0) {
      A /= gcd;
      B /= gcd;
      C /= gcd;
    }
    if (A != 0) {
      if (A < 0) {
        A *= -1;
        B *= -1;
        C *= -1;
      }
    } else if (B != 0) {
      if (B < 0) {
        A *= -1;
        B *= -1;
        C *= -1;
      }
    }
  }
};
bool operator<(const Line& a, const Line& b) {
  if (a.A != b.A) return a.A < b.A;
  if (a.B != b.B) return a.B < b.B;
  return a.C < b.C;
}
int x[1505], y[1505], r[1505];
const int MAX = 300005;
vector<pair<int, int> > leftP[MAX], rightP[MAX];
map<Line, int> toID;
int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 0, max_ = (N); i < max_; ++i) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (make_pair(x1, y1) > make_pair(x2, y2)) {
      swap(x1, x2);
      swap(y1, y2);
    }
    int id;
    Line l(x1, y1, x2, y2);
    auto it = toID.find(l);
    if (it != toID.end())
      id = it->second;
    else {
      id = (int)(toID).size();
      toID.insert(make_pair(l, id));
    }
    leftP[id].push_back(make_pair(2 * x1, 2 * y1));
    rightP[id].push_back(make_pair(2 * x2, 2 * y2));
  }
  for (int i = 0, max_ = (MAX); i < max_; ++i) {
    if ((int)(leftP[i]).size() == 0) continue;
    sort((leftP[i]).begin(), (leftP[i]).end());
    sort((rightP[i]).begin(), (rightP[i]).end());
  }
  for (int i = 0, max_ = (M); i < max_; ++i)
    scanf("%d %d %d", &x[i], &y[i], &r[i]);
  long long res = 0;
  for (int i = 0, max_ = (M); i < max_; ++i)
    for (int j = (i + 1), max_ = (M); j < max_; ++j) {
      if (r[i] != r[j]) continue;
      if (4 * r[i] * r[j] >=
          (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))
        continue;
      int cx = (x[i] + x[j]);
      int cy = (y[i] + y[j]);
      int dx = x[j] - x[i];
      int dy = y[j] - y[i];
      int nx = cx + dy;
      int ny = cy - dx;
      Line l(cx, cy, nx, ny);
      l.A *= 2;
      l.B *= 2;
      int gcd = abs(GCD(l.A, GCD(l.B, l.C)));
      l.A /= gcd;
      l.B /= gcd;
      l.C /= gcd;
      auto it = toID.find(l);
      if (it != toID.end()) {
        int id = it->second;
        pair<int, int> p = make_pair(cx, cy);
        int itL = leftP[id].end() -
                  upper_bound((leftP[id]).begin(), (leftP[id]).end(), p);
        int itR = upper_bound((rightP[id]).begin(), (rightP[id]).end(), p) -
                  rightP[id].begin();
        while (itR >= 0 && rightP[id][itR] >= p) --itR;
        int contrib = max(0, (int)(leftP[id]).size() - itL - (itR + 1));
        res += contrib;
      }
    }
  printf("%I64d\n", res);
  return 0;
}
