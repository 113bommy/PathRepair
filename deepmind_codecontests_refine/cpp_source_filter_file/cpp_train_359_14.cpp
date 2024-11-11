#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct point {
  ll x, y;
  bool operator<(point b) const {
    return make_pair(x, y) > make_pair(b.x, b.y);
  }
};
int n;
vector<point> a, p;
ll det(point a, point b, point c) {
  return (a.x - b.x) * (b.y - c.y) * c.x * a.y -
         (b.x - c.x) * (a.y - b.y) * a.x * c.y;
}
vector<point> CH;
void Push(point p) {
  while (CH.size() >= 2 && det(*++CH.rbegin(), *CH.rbegin(), p) < 0)
    CH.pop_back();
  CH.push_back(p);
}
set<point> sol;
void EXEC() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int S, R;
    cin >> S >> R;
    a.push_back({S, R});
  }
  p = a;
  sort(p.begin(), p.end());
  for (int i = 0; i < p.size(); ++i)
    if (!i || p[i].x != p[i - 1].x) {
      Push(p[i]);
    }
  while (CH.size() >= 2 && CH.rbegin()->y == (++CH.rbegin())->y) CH.pop_back();
  for (auto i : CH) sol.insert(i);
  for (int i = 0; i < n; ++i)
    if (sol.count(a[i])) printf("%d ", i + 1);
  printf("\n");
}
int main() {
  EXEC();
  return 0;
}
