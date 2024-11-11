#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10, MAX = 2e9 + 5e8, SQRT = 1003;
pair<pair<int, int>, int> a[MAXN];
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first / SQRT == b.first.first / SQRT)
    return a.first.second < b.first.second;
  return a.first.first < b.first.first;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) cout << a[i].second << " ";
  return 0;
}
