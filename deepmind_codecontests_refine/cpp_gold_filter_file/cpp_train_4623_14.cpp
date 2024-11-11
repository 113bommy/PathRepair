#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
pair<int, int> a[N], first[N], second[N];
bool chk() {
  for (int i = 1; i <= n; i++)
    a[first[i].second].first = i, a[second[i].second].second = i;
  bool f1 = false, f2 = false;
  int m = (n + 1) / 2;
  for (int i = 1; i <= n; i++)
    if (n & 1) {
      if (a[i].first < m && a[i].second < m) f1 = true;
      if (a[i].first > m && a[i].second > m) f1 = true;
      if (a[i].first < m && a[i].second > m) f2 = true;
      if (a[i].first > m && a[i].second < m) f2 = true;
    } else {
      if (a[i].first <= m && a[i].second <= m) f1 = true;
      if (a[i].first > m && a[i].second > m) f1 = true;
      if (a[i].first <= m && a[i].second > m) f2 = true;
      if (a[i].first > m && a[i].second <= m) f2 = true;
    }
  return f1 && f2;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &a[i].first, &a[i].second),
        first[i] = make_pair(a[i].first, i),
        second[i] = make_pair(a[i].second, i);
  if (n & 1) {
    int m = (n + 1) / 2;
    nth_element(first + 1, first + m, first + n + 1),
        nth_element(second + 1, second + m, second + n + 1);
    long long ans = 0;
    for (int i = m + 1; i <= n; i++)
      ans += 2LL * (first[i].first + second[i].first);
    for (int i = 1; i <= m - 1; i++)
      ans -= 2LL * (first[i].first + second[i].first);
    if (first[m].second != second[m].second)
      cout << ans << endl;
    else {
      if (chk()) {
        nth_element(first + 1, first + m - 1, first + m);
        nth_element(first + m + 1, first + m + 1, first + n + 1);
        nth_element(second + 1, second + m - 1, second + m);
        nth_element(second + m + 1, second + m + 1, second + n + 1);
        ans -= 2 * min(min(first[m].first - first[m - 1].first,
                           first[m + 1].first - first[m].first),
                       min(second[m].first - second[m - 1].first,
                           second[m + 1].first - second[m].first));
      }
      cout << ans << endl;
    }
  } else {
    int m = n / 2;
    nth_element(first + 1, first + m, first + n + 1);
    nth_element(first + m + 1, first + m + 1, first + n + 1);
    nth_element(second + 1, second + m, second + n + 1);
    nth_element(second + m + 1, second + m + 1, second + n + 1);
    long long ans = 0;
    for (int i = m + 1; i <= n; i++)
      ans += 2LL * (first[i].first + second[i].first);
    for (int i = 1; i <= m; i++)
      ans -= 2LL * (first[i].first + second[i].first);
    if (chk())
      ans -= 2LL * min(first[m + 1].first - first[m].first,
                       second[m + 1].first - second[m].first);
    cout << ans << endl;
  }
  return 0;
}
