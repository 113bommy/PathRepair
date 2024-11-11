#include <bits/stdc++.h>
using namespace std;
vector<int> open, close, num;
string brac;
void build(int node, int l, int r) {
  if (l == r) {
    if (brac[l] == '(') {
      open[node] = 1;
      close[node] = 0;
      num[node] = 0;
    } else {
      open[node] = 0;
      close[node] = 1;
      num[node] = 0;
    }
    return;
  }
  build(2 * node, l, (l + r) / 2);
  build(2 * node + 1, (l + r) / 2 + 1, r);
  int t = min(open[2 * node], close[2 * node + 1]);
  num[node] = num[2 * node] + num[2 * node + 1] + t;
  open[node] = open[2 * node] + open[2 * node + 1] - t;
  close[node] = close[2 * node] + close[2 * node + 1] - t;
}
pair<int, pair<int, int> > query(int node, int l, int r, int i, int j) {
  if (j < l || i > r) {
    return pair<int, pair<int, int> >(-1, pair<int, int>(0, 0));
  }
  if (i <= l && r <= j) {
    return pair<int, pair<int, int> >(num[node],
                                      pair<int, int>(open[node], close[node]));
  }
  pair<int, pair<int, int> > lVal = query(2 * node, l, (l + r) / 2, i, j);
  pair<int, pair<int, int> > rVal =
      query(2 * node + 1, (l + r) / 2 + 1, r, i, j);
  if (lVal.first == -1) {
    return rVal;
  }
  if (rVal.first == -1) {
    return lVal;
  }
  int t = min(lVal.second.first, rVal.second.second);
  return pair<int, pair<int, int> >(
      lVal.first + rVal.first + t,
      pair<int, int>(lVal.second.first + rVal.second.first - t,
                     lVal.second.second + rVal.second.second - t));
}
int main() {
  cin >> brac;
  open.assign(4 * brac.size(), 0);
  close.assign(4 * brac.size(), 0);
  num.assign(4 * brac.size(), 0);
  build(1, 0, brac.size() - 1);
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cout << query(1, 0, brac.size() - 1, a - 1, b - 1).first * 2 << endl;
  }
  return 0;
}
