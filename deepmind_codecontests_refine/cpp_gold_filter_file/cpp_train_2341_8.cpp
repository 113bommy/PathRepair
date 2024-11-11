#include <bits/stdc++.h>
using namespace std;
int n, l;
void quit() { printf("NO\n"), exit(0); }
vector<int> make(vector<pair<int, pair<long long, long long> > > X, int s) {
  vector<int> res;
  int prev = 0;
  int prevS = 0;
  for (auto cur : X) {
    long long hereS = cur.second.first - s * cur.second.second;
    for (int i = 0; i < hereS - prevS; i++) res.push_back(1);
    int here = cur.first;
    for (int i = 0; i < here - prev - (hereS - prevS); i++) res.push_back(0);
    prev = here;
    prevS = hereS;
  }
  while (prevS < s) res.push_back(1), prevS += 1;
  while (res.size() < l) res.push_back(0);
  return res;
}
vector<int> solve(vector<pair<long long, long long> > pts) {
  for (auto& p : pts) {
    if ((p.first + p.second) % 2 == 1) quit();
    p.second = (p.second + p.first) / 2;
  }
  vector<pair<int, pair<long long, long long> > > X;
  for (auto p : pts)
    X.push_back(make_pair(p.first % l, make_pair(p.second, p.first / l)));
  sort(X.begin(), X.end());
  long long low = 0;
  long long high = l;
  auto prev = X[0];
  for (auto cur : X) {
    if (cur == prev) continue;
    int z = cur.first - prev.first;
    long long x = cur.second.first - prev.second.first;
    long long y = -cur.second.second + prev.second.second;
    if (0 <= x && x <= z) {
      if (y > 0) high = min(high, (z - x) / y);
    } else if (x < 0) {
      if (y <= 0) quit();
      low = max(low, (-x + y - 1) / y);
      high = min(high, (-x + z + y - 1) / y);
    } else if (x > z) {
      if (y >= 0) quit();
      y = -y;
      low = max(low, (x - z + y - 1) / y);
      high = min(high, (x + y - 1) / y);
    }
    prev = cur;
  }
  for (long long i = low; i <= high; i++) {
    long long val = prev.second.first - i * prev.second.second;
    if (val <= i && val + l - prev.first >= i) return make(X, i);
  }
  quit();
}
long long t[200013];
long long x[200013];
long long y[200013];
char rev[4] = {'L', 'U', 'D', 'R'};
int main() {
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &t[i], &x[i], &y[i]);
  vector<int> one, two;
  for (int r = -1; r <= 1; r++) {
    if (!r) continue;
    vector<pair<long long, long long> > has;
    for (int i = 0; i <= n; i++)
      has.push_back(make_pair(t[i], x[i] + r * y[i]));
    one = solve(has);
    swap(one, two);
  }
  for (int i = 0; i < l; i++) printf("%c", rev[one[i] * 2 + two[i]]);
  printf("\n");
  return 0;
}
