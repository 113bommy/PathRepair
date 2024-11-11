#include <bits/stdc++.h>
using namespace std;
struct segment {
  int a, b;
  int count;
};
struct comp_a {
  bool operator()(const segment& a, const segment& b) {
    if (a.a != b.a) return a.a < b.a;
    return a.b < b.b;
  }
};
struct comp_b {
  bool operator()(const segment& a, const segment& b) {
    if (a.b != b.b) return a.b < b.b;
    return a.a < b.a;
  }
};
struct comp_count {
  bool operator()(const segment& a, const segment& b) {
    if (b.count != a.count) return b.count < a.count;
    if (a.a != b.a) return a.a < b.a;
    return a.b < b.b;
  }
};
int main() {
  int n;
  cin >> n;
  set<segment, comp_a> q1;
  set<segment, comp_b> q2;
  set<segment, comp_count> q3;
  q3.insert({0, 0, 0});
  for (int i = 0; i < n; i++) {
    int x, w;
    cin >> x >> w;
    q1.insert({x - w, x + w, 1});
  }
  int ans = 0;
  for (auto s : q1) {
    while (!q2.empty() && q2.begin()->b >= s.a) {
      q3.insert(*q2.begin());
      q2.erase(q2.begin());
    }
    s.count = q3.begin()->count + 1;
    ans = max(ans, s.count);
    q2.insert(s);
  }
  cout << ans;
}
