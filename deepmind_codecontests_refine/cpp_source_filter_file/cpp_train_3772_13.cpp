#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<pair<int, int>, int> q[10100];
int w[10100];
bool comp1(const pair<pair<int, int>, int> &a,
           const pair<pair<int, int>, int> &b) {
  if (a.first.second != b.first.second) return a.first.second < b.first.second;
  return a.first.first < b.first.first;
}
bool comp2(const pair<pair<int, int>, int> &a,
           const pair<pair<int, int>, int> &b) {
  int auxa = a.first.first + a.first.second,
      auxb = b.first.first + b.first.second;
  if (auxa != auxb) return auxa < auxb;
  return a.first.second < b.first.second;
}
bool comp3(const pair<pair<int, int>, int> &a,
           const pair<pair<int, int>, int> &b) {
  int auxa = a.first.first - a.first.second,
      auxb = b.first.first - b.first.second;
  if (auxa != auxb) return auxa < auxb;
  return a.first.first < b.first.first;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> q[i].first.first >> q[i].first.second;
    q[i].second = i;
  }
  memset(w, 0, sizeof(w));
  sort(q, q + m);
  int add = 0;
  for (int i = 1; i < m; i++) {
    if (q[i].first.first == q[i - 1].first.first)
      add = 1;
    else
      add = 0;
    w[q[i].second] += add;
  }
  add = 0;
  for (int i = m - 2; i >= 0; i--) {
    if (q[i].first.first == q[i + 1].first.first)
      add = 1;
    else
      add = 0;
    w[q[i].second] += add;
  }
  sort(q, q + m, comp1);
  add = 0;
  for (int i = 1; i < m; i++) {
    if (q[i].first.second == q[i - 1].first.second)
      add = 1;
    else
      add = 0;
    w[q[i].second] += add;
  }
  add = 0;
  for (int i = m - 2; i >= 0; i--) {
    if (q[i].first.second == q[i + 1].first.second)
      add = 1;
    else
      add = 0;
    w[q[i].second] += add;
  }
  sort(q, q + m, comp2);
  add = 0;
  for (int i = 1; i < m; i++) {
    if (q[i].first.second + q[i].first.first ==
        q[i - 1].first.second + q[i - 1].first.first)
      add = 1;
    else
      add = 0;
    w[q[i].second] += add;
  }
  add = 0;
  for (int i = m - 2; i >= 0; i--) {
    if (q[i].first.second + q[i].first.first ==
        q[i + 1].first.second + q[i + 1].first.first)
      add = 1;
    else
      add = 0;
    w[q[i].second] += add;
  }
  sort(q, q + m, comp3);
  add = 0;
  for (int i = 1; i < m; i++) {
    if (q[i].first.first - q[i].first.second ==
        q[i - 1].first.first - q[i - 1].first.second)
      add = 1;
    else
      add = 0;
    w[q[i].second] += add;
  }
  add = 0;
  for (int i = m - 2; i >= 0; i--) {
    if (q[i].first.first - q[i].first.second ==
        q[i + 1].first.first - q[i + 1].first.second)
      add = 1;
    else
      add = 0;
    w[q[i].second] += add;
  }
  vector<int> ret(8, 0);
  for (int i = 0; i < m; i++) {
    ret[w[i]]++;
  }
  for (int i = 0; i < 8; i++) {
    if (i) cout << " ";
    cout << ret[i];
  }
  cout << endl;
  return 0;
}
