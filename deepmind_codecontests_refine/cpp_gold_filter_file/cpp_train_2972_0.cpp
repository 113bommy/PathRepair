#include <bits/stdc++.h>
using namespace std;
struct tocka {
  long long int x, y;
  bool operator<(const tocka &p) const {
    if (x == p.x) return y < p.y;
    return x < p.x;
  }
};
vector<tocka> v, gornji, donji, convex;
long long int ccw(tocka a, tocka b, tocka c) {
  return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}
int main() {
  long long int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    tocka t;
    scanf("%I64d%I64d", &t.x, &t.y);
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    while (gornji.size() >= 2 &&
           ccw(gornji[gornji.size() - 1], gornji[gornji.size() - 2], v[i]) < 0)
      gornji.pop_back();
    gornji.push_back(v[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    while (donji.size() >= 2 &&
           ccw(donji[donji.size() - 1], donji[donji.size() - 2], v[i]) < 0)
      donji.pop_back();
    donji.push_back(v[i]);
  }
  for (int i = 0; i < gornji.size() - 1; i++) convex.push_back(gornji[i]);
  for (int i = 0; i < donji.size() - 1; i++) convex.push_back(donji[i]);
  int i = 0, j = 1, k = 2;
  int l = convex.size();
  for (int x = 0; x < 3 * n; x++) {
    while (abs(ccw(convex[i], convex[j], convex[k])) <
           abs(ccw(convex[i], convex[j], convex[(k + 1) % l])))
      k = (k + 1) % l;
    while (abs(ccw(convex[i], convex[j], convex[k])) <
           abs(ccw(convex[i], convex[(j + 1) % l], convex[k])))
      j = (j + 1) % l;
    while (abs(ccw(convex[i], convex[j], convex[k])) <
           abs(ccw(convex[(i + 1) % l], convex[j], convex[k])))
      i = (i + 1) % l;
  }
  for (int x = 0; x < 3 * n; x++) {
    while (abs(ccw(convex[i], convex[j], convex[k])) <
           abs(ccw(convex[i], convex[j], convex[(k - 1 + l) % l])))
      k = (k - 1 + l) % l;
    while (abs(ccw(convex[i], convex[j], convex[k])) <
           abs(ccw(convex[i], convex[(j - 1 + l) % l], convex[k])))
      j = (j - 1 + l) % l;
    while (abs(ccw(convex[i], convex[j], convex[k])) <
           abs(ccw(convex[(i - 1 + l) % l], convex[j], convex[k])))
      i = (i - 1 + l) % l;
  }
  cout << convex[i].x + (convex[j].x - convex[k].x) << " "
       << convex[i].y + (convex[j].y - convex[k].y) << endl;
  cout << convex[j].x + (convex[k].x - convex[i].x) << " "
       << convex[j].y + (convex[k].y - convex[i].y) << endl;
  cout << convex[k].x + (convex[i].x - convex[j].x) << " "
       << convex[k].y + (convex[i].y - convex[j].y) << endl;
  return 0;
}
