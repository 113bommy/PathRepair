#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, m;
vector<tuple<int, int, int> > q;
vector<int> w(8, 0);
map<int, bool> mark;
bool cmp1(const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {
  return get<1>(t1) < get<1>(t2);
}
bool cmp2(const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {
  return get<0>(t1) + get<1>(t1) < get<0>(t2) + get<1>(t2);
}
bool cmp3(const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {
  return get<0>(t1) - get<1>(t1) < get<0>(t2) - get<1>(t2);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int r, c;
    cin >> r >> c;
    q.emplace_back(r, c, 0);
  }
  sort(q.begin(), q.end());
  for (int i = 0; i < m; i++) {
    int r, c, v;
    tie(r, c, v) = q[i];
    if (mark[c]) get<2>(q[i])++;
    mark[c] = 1;
  }
  mark.clear();
  for (int i = m - 1; i >= 0; i--) {
    int r, c, v;
    tie(r, c, v) = q[i];
    if (mark[c]) get<2>(q[i])++;
    mark[c] = 1;
  }
  sort(q.begin(), q.end(), cmp1);
  mark.clear();
  for (int i = 0; i < m; i++) {
    int r, c, v;
    tie(r, c, v) = q[i];
    if (mark[r]) get<2>(q[i])++;
    mark[r] = 1;
  }
  mark.clear();
  for (int i = m - 1; i >= 0; i--) {
    int r, c, v;
    tie(r, c, v) = q[i];
    if (mark[r]) get<2>(q[i])++;
    mark[r] = 1;
  }
  sort(q.begin(), q.end(), cmp2);
  mark.clear();
  for (int i = 0; i < m; i++) {
    int r, c, v;
    tie(r, c, v) = q[i];
    if (mark[r + c]) get<2>(q[i])++;
    mark[r + c] = 1;
  }
  mark.clear();
  for (int i = m - 1; i >= 0; i--) {
    int r, c, v;
    tie(r, c, v) = q[i];
    if (mark[r + c]) get<2>(q[i])++;
    mark[r + c] = 1;
  }
  sort(q.begin(), q.end(), cmp3);
  mark.clear();
  for (int i = 0; i < m; i++) {
    int r, c, v;
    tie(r, c, v) = q[i];
    if (mark[r - c]) get<2>(q[i])++;
    mark[r - c] = 1;
  }
  mark.clear();
  for (int i = m - 1; i >= 0; i--) {
    int r, c, v;
    tie(r, c, v) = q[i];
    if (mark[r - c]) get<2>(q[i])++;
    mark[r - c] = 1;
  }
  for (auto &it : q) w[get<2>(it)]++;
  for (int i = 0; i <= 8; i++) cout << w[i] << ' ';
  cout << '\n';
  ;
  return 0;
}
