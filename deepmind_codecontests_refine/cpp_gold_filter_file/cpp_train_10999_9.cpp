#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n;
pair<pair<int, int>, int> a[maxn];
bool cmp(pair<pair<int, int>, int> x1, pair<pair<int, int>, int> x2) {
  if (x1.first.first != x2.first.first) return x1.first.first < x2.first.first;
  return x1.first.second > x2.first.second;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a1, a2;
    cin >> a1 >> a2;
    a[i] = make_pair(make_pair(a1, a2), i);
  }
  sort(a, a + n, cmp);
  cout << endl;
  for (int i = 0; i < n - 1; i++) {
    if (a[i].first.second >= a[i + 1].first.second) {
      return cout << a[i + 1].second + 1 << " " << a[i].second + 1, 0;
    }
  }
  cout << "-1 -1";
}
