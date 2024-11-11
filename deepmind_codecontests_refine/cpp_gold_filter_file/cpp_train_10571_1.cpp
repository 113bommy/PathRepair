#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1E5 + 10;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
int n, m, cookie;
set<pair<int, int> > A, B;
int touch[MAX], minr[MAX], maxr[MAX];
vector<pair<int, int> > cv;
bool is_four(int x, int y) {
  if (x < 1 || x > n) return false;
  if (touch[x] != cookie) return false;
  if (A.find(make_pair(x, y)) != A.end()) return false;
  return minr[x] <= y && y <= maxr[x];
}
long long sqr(long long a) { return a * a; }
long long dist(const pair<int, int>& a, const pair<int, int>& b) {
  return sqr(a.first - b.first) + sqr(a.second - b.second);
}
long long ccw(const pair<int, int>& o, const pair<int, int>& a,
              const pair<int, int>& b) {
  return (long long)(a.first - o.first) * (b.second - o.second) -
         (long long)(a.second - o.second) * (b.first - o.first);
}
bool cmp(const pair<int, int>& l, const pair<int, int>& r) {
  long long c = ccw(cv[0], l, r);
  return c < 0 || (c == 0 && dist(cv[0], l) < dist(cv[0], r));
}
void graham_scan() {
  for (int i = 1; i < (int)cv.size(); i++)
    if (cv[i].first < cv[0].first ||
        (cv[i].first == cv[0].first && cv[i].second < cv[0].second))
      swap(cv[i], cv[0]);
  sort(cv.begin() + 1, cv.end(), cmp);
  cv.push_back(cv[0]);
  int top = 1;
  for (int i = 2; i < (int)cv.size(); i++) {
    while (top > 0 && ccw(cv[top - 1], cv[top], cv[i]) >= 0) top--;
    cv[++top] = cv[i];
  }
  cv.resize(top);
}
int main() {
  while (true) {
    A.clear();
    B.clear();
    cv.resize(0);
    scanf("%d%d", &n, &m);
    if (n == 0 && m == 0) break;
    cookie++;
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      A.insert(make_pair(x, y));
      if (touch[x] != cookie) {
        touch[x] = cookie;
        minr[x] = y;
        maxr[x] = y;
      }
      minr[x] = min(minr[x], y);
      maxr[x] = max(maxr[x], y);
    }
    for (auto a : A) {
      for (int i = 0; i < 4; i++) {
        int x = a.first + dx[i];
        int y = a.second + dy[i];
        if (is_four(x, y)) B.insert(make_pair(x, y));
      }
    }
    for (auto b : B) A.insert(b);
    for (auto a : A)
      if (A.find(make_pair(a.first + 1, a.second)) != A.end() &&
          A.find(make_pair(a.first, a.second + 1)) != A.end() &&
          A.find(make_pair(a.first + 1, a.second + 1)) != A.end()) {
        cv.push_back(a);
      }
    graham_scan();
    printf("%d\n", (int)cv.size());
    for (auto v : cv) printf("%d %d\n", v.first, v.second);
  }
}
