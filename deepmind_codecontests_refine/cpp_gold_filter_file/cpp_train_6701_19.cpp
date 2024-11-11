#include <bits/stdc++.h>
using namespace std;
int ABS(int a) {
  if (a < 0) return (-a);
  return a;
}
vector<int> q;
void f(vector<int> &p) {
  vector<int> v(p.size(), 0);
  int i;
  for (i = (1); i < (p.size()); ++i) v[i] = p[q[i]];
  p = v;
}
void inversef(vector<int> &p) {
  vector<int> v(p.size(), 0);
  int i;
  for (i = (1); i < (p.size()); ++i) v[q[i]] = p[i];
  p = v;
}
int main() {
  int n, i, k;
  cin >> n >> k;
  q.resize(n + 1);
  for (i = (1); i < (n + 1); ++i) cin >> q[i];
  vector<int> want(n + 1);
  for (i = (1); i < (n + 1); ++i) cin >> want[i];
  vector<int> v(n + 1);
  for (i = (1); i < (n + 1); ++i) v[i] = i;
  int steps = 0;
  bool ans = false;
  while (steps <= k) {
    if (v == want) break;
    steps++;
    f(v);
  }
  int lststep = 200;
  if (steps <= k) {
    if (steps != 0) {
      if ((k - steps) % 2 == 0) ans = true;
    }
    lststep = steps;
  }
  for (i = (1); i < (n + 1); ++i) v[i] = i;
  steps = 0;
  while (steps <= k) {
    if (v == want) break;
    steps++;
    inversef(v);
  }
  if (steps <= k) {
    if (steps != 0) {
      if ((k - steps) % 2 == 0) ans = true;
    }
  }
  if (steps == 1 && lststep == 1 && k != 1) ans = false;
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}
