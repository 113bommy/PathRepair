#include <bits/stdc++.h>
using namespace std;
int n, s;
pair<int, int> d[200005];
long long int fon(int k) {
  long long int ret = 0;
  int say = 0;
  vector<int> v, v2;
  for (int i = 0; i < n; i++)
    if (d[i].first <= k - 2 || d[i].first > k) {
      v.push_back(d[i].second);
      if (d[i].first <= k - 2) say++;
    } else
      v2.push_back(d[i].second);
  sort(v2.begin(), v2.end());
  int qw = (n - s + 1) - say;
  if (qw < 0) qw = 0;
  if (qw > k) return -1;
  for (int i = 0; i < qw; i++) {
    if (i == v2.size()) return -1;
    ret += v2[i];
  }
  for (int i = qw; i < v2.size(); i++) v.push_back(v2[i]);
  sort(v.begin(), v.end());
  for (int i = 0; i < k - qw; i++)
    if (i == v.size())
      return -1;
    else
      ret += v[i];
  return ret;
}
int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &d[i].first, &d[i].second);
  }
  sort(d, d + n);
  int a = 0, b = n;
  while (a != b) {
    if (fon(((a + b) / 2)) == -1)
      a = ((a + b) / 2) + 1;
    else
      b = ((a + b) / 2);
  }
  long long int mn = fon(a);
  if (mn == -1) return printf("-1\n"), 0;
  for (int i = a; i <= n && i < a + 100; i++) mn = min(fon(i), mn);
  printf("%lld\n", mn);
}
