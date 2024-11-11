#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<pair<long, long>, int> > a;
int dd[100005];
void input() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    long l, r;
    cin >> l >> r;
    a.push_back(pair<pair<long, long>, int>(pair<long, long>(l, r), i));
  }
}
bool cmp1(pair<pair<long, long>, int> x, pair<pair<long, long>, int> y) {
  if (x.first.second == y.first.second) return x.first.first < y.first.first;
  return x.first.second < y.first.second;
}
bool cmp(pair<pair<long, long>, int> x, pair<pair<long, long>, int> y) {
  if (x.first.first == y.first.first) return x.first.second > y.first.second;
  return x.first.first < y.first.first;
}
void process() {
  sort(a.begin(), a.end(), cmp1);
  for (int i = 1; i < n; ++i)
    if (a[i].first.second == a[i - 1].first.second) {
      cout << a[i].second;
      return;
    }
  sort(a.begin(), a.end(), cmp);
  for (int i = 1; i < n; ++i)
    if (a[i].first.first == a[i - 1].first.first) {
      cout << a[i].second;
      return;
    }
  long mid = a[0].second;
  for (int i = 1; i < n - 1; ++i) {
    if ((a[i + 1].first.first - a[i - 1].first.second <= 1 &&
         a[i].first.second < a[i + 1].first.second) ||
        (a[i].first.second < mid)) {
      cout << a[i].second;
      return;
    }
    mid = max(mid, a[i].first.second);
  }
  if (a[n - 1].first.second <= mid)
    cout << a[n - 1].second;
  else
    cout << -1;
}
int main() {
  input();
  process();
  return 0;
}
