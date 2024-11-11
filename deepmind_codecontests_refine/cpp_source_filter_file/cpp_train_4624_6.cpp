#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v1;
pair<int, int> p1;
int a[1234567];
string s;
int dp[1001];
long long pow1(long long x, long long y) {
  if (y == 0) return 1;
  long long temp = pow1(x, y / 2) % 1000000007;
  if (y % 2 == 0)
    return (temp * temp) % 1000000007;
  else
    return (((temp * temp) % 1000000007) * x) % 1000000007;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}
int main() {
  int t;
  int n, i, j, k, m, l;
  scanf("%d", &n);
  int count = 0;
  for (i = 0; i < n; i++) {
    scanf("%d%d", &j, &k);
    if (j == 0 || k == 0) count++;
    v1.push_back(make_pair(j, k));
  }
  sort(v1.begin(), v1.end(), cmp);
  int ans = count * 4 + (n - count) * 6;
  printf("%d\n", ans);
  for (i = 0; i < n; i++) {
    int p = v1[i].first;
    int q = v1[i].second;
    if (p == 0) {
      if (q < 0)
        printf("1 %d D\n2\n1 %d U\n3\n", abs(q), abs(q));
      else
        printf("1 %d U\n2\n1 %d D\n3\n", q, q);
    } else if (q == 0) {
      if (p < 0)
        printf("1 %d L\n2\n1 %d D\n3\n", abs(p), abs(p));
      else
        printf("1 %d R\n2\n1 %d L\n3\n", p, p);
    } else {
      if (p < 0 && q < 0)
        printf("1 %d L\n1 %d D\n2\n1 %d R\n1 %d U\n3\n", abs(p), abs(q), abs(p),
               abs(q));
      else if (p > 0 && q > 0)
        printf("1 %d R\n1 %d U\n2\n1 %d L\n1 %d D\n3\n", p, q, p, q);
      else if (p > 0)
        printf("1 %d R\n1 %d D\n2\n1 %d L\n1 %d U\n3\n", p, abs(q), p, abs(q));
      else
        printf("1 %d L\n1 %d U\n2\n1 %d R\n1 %d D\n3\n", abs(p), q, abs(p), q);
    }
  }
  return 0;
}
