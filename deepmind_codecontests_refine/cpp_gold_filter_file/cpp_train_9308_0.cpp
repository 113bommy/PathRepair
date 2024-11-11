#include <bits/stdc++.h>
using namespace std;
template <class P, class Q>
void mmin(P &a, const Q &b) {
  if (b < a) a = b;
}
template <class P, class Q>
void mmax(P &a, const Q &b) {
  if (b > a) a = b;
}
template <class P>
P GCD(P a, P b) {
  if (a < b) swap(a, b);
  P c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
const int MAXn = 2000;
int n, m;
pair<int, int> a[MAXn], b[MAXn];
vector<pair<int, pair<int, int> > > vc1, vc2;
bool mark[MAXn][MAXn];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second != b.second ? a.second < b.second : a.first < b.first;
}
inline bool coincide(const pair<int, pair<int, int> > &a,
                     const pair<int, pair<int, int> > &b) {
  return b.second.first <= a.first && a.first <= b.second.second &&
         a.second.first <= b.first && b.first <= a.second.second;
}
inline bool check(int x) {
  vc1.clear();
  vc2.clear();
  for (int i = 0; i < (n); ++i) fill_n(mark[i], n, 0);
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && a[j].first == a[i].first &&
           a[j - 1].second + 2 * x >= a[j].second - 2 * x)
      ++j;
    vc1.push_back(make_pair(
        a[i].first, make_pair(a[i].second - 2 * x, a[j - 1].second + 2 * x)));
    i = j;
  }
  for (int i = 0; i < m;) {
    int j = i + 1;
    while (j < m && b[j].second == b[i].second &&
           b[j - 1].first + 2 * x >= b[j].first - 2 * x)
      ++j;
    vc2.push_back(make_pair(
        b[i].second, make_pair(b[i].first - 2 * x, b[j - 1].first + 2 * x)));
    i = j;
  }
  for (int j = 0; j < ((int)(vc2).size()); ++j) {
    vector<int> vc;
    for (int i = 0; i < ((int)(vc1).size()); ++i)
      if (coincide(vc1[i], vc2[j])) {
        vc.push_back(i);
      }
    for (int i = 0; i < ((int)(vc).size()); ++i)
      for (int j = (i + 1); j < ((int)(vc).size()); ++j)
        if (mark[vc[i]][vc[j]])
          return true;
        else
          mark[vc[i]][vc[j]] = 1;
  }
  return false;
}
inline int BS() {
  int s = -1, e = 2e6;
  if (!check(e)) return -1;
  while (s + 1 < e) {
    int mid = s + e >> 1;
    if (check(mid))
      e = mid;
    else
      s = mid;
  }
  return e;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < (n); ++i) {
    int x, y;
    cin >> x >> y;
    a[i] = pair<int, int>(x + y, x - y);
  }
  for (int i = 0; i < (m); ++i) {
    int x, y;
    cin >> x >> y;
    b[i] = pair<int, int>(x + y, x - y);
  }
  sort(a, a + n);
  sort(b, b + m, cmp);
  int ans = BS();
  if (ans == -1)
    cout << "Poor Sereja!" << endl;
  else
    cout << ans << endl;
  return 0;
}
