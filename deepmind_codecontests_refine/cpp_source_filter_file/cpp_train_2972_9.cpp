#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y;
  pt operator-(pt p) { return {x - p.x, y - p.y}; }
  pt operator+(pt p) { return {x + p.x, y + p.y}; }
  bool operator==(pt p) { return x == p.x && y == p.y; }
  long long operator*(pt p) { return x * p.y - y * p.x; }
};
vector<pt> points;
long long S(int i, int j, int g) {
  pt one = points[i] - points[j], two = points[i] - points[g];
  return abs(one * two);
}
int main() {
  int n, a = 0, b = 1, c = 2;
  long long s;
  cin >> n >> s;
  points.resize(n);
  for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
  while (1) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
      long long cur_s = S(a, b, c);
      if (cur_s < S(i, b, c)) {
        flag = 1;
        a = i;
      } else if (cur_s < S(a, i, c)) {
        flag = 1;
        b = i;
      } else if (cur_s < S(a, b, i)) {
        flag = 1;
        c = i;
      }
    }
    if (!flag) break;
  }
  pt raznost = points[a] - points[b], raznost2 = points[b] - points[c];
  pt ans1 = points[c] + raznost, ans2 = points[c] - raznost,
     ans3 = points[a] - raznost2, ans4 = points[a] + raznost2;
  if (ans1 == ans3) {
    cout << ans1.x << " " << ans1.y << '\n'
         << ans2.x << " " << ans2.y << '\n'
         << ans4.x << " " << ans4.y;
    return 0;
  }
  if (ans1 == ans2) {
    cout << ans1.x << " " << ans1.y << '\n'
         << ans3.x << " " << ans3.y << '\n'
         << ans4.x << " " << ans4.y;
    return 0;
  }
  if (ans1 == ans4) {
    cout << ans1.x << " " << ans1.y << '\n'
         << ans2.x << " " << ans2.y << '\n'
         << ans3.x << " " << ans3.y;
    return 0;
  }
}
