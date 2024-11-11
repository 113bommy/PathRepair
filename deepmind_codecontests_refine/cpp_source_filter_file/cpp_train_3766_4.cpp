#include <bits/stdc++.h>
using namespace std;
class FenwickTree {
 public:
  int n;
  vector<int> fenw;
  FenwickTree(int _n) : n(_n) { fenw.resize(n + 1, 0); }
  void add(int k, int x) {
    k++;
    while (k <= n) {
      fenw[k] += x;
      k += k & -k;
    }
  }
  int sum(int k) {
    k++;
    int s = 0;
    while (k >= 1) {
      s += fenw[k];
      k -= k & -k;
    }
    return s;
  }
  int sum(int ll, int rr) { return sum(rr) - sum(ll - 1); }
};
struct Segment {
  int x1, y1, x2, y2;
  bool h() const { return y1 == y2; }
};
const int SHIFT = 5000;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<Segment> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
    v[i].y1 += SHIFT;
    v[i].y2 += SHIFT;
    if (v[i].x1 > v[i].x2) {
      swap(v[i].x1, v[i].x2);
    }
    if (v[i].y1 > v[i].y2) {
      swap(v[i].y1, v[i].y2);
    }
  }
  sort(v.begin(), v.end(), [](const Segment &a, const Segment &b) {
    if (a.x2 != b.x2) {
      return a.x2 < b.x2;
    }
    return b.h();
  });
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].h()) {
      continue;
    }
    FenwickTree ft(10001);
    for (int j = 0; j < n; j++) {
      if (v[j].h() && v[j].x1 <= v[i].x1 && v[i].x1 <= v[j].x2 &&
          v[j].y1 <= v[i].y1 && v[i].y1 <= v[j].y2) {
        ft.add(v[j].y1, 1);
      }
    }
    for (int j = 0; j < n; j++) {
      if (v[j].h()) {
        if (v[j].x2 >= v[i].x1 && ft.sum(v[j].y1, v[j].y1) == 1) {
          ft.add(v[j].y1, -1);
        }
      } else {
        if (v[j].x1 > v[i].x1) {
          int cnt = ft.sum(v[j].y1, v[j].y2);
          ans += 1LL * cnt * (cnt - 1) / 2;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
