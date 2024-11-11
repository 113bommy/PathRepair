#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
vector<long long> v;
vector<int> vi;
int n, m, q, k;
int a[2002];
int dp1[2002][2002] = {0};
int dp2[2002][2002] = {0};
int one[2002] = {0};
int two[2002] = {0};
void func1(int ind) {
  vector<int> d;
  for (int i = ind; i <= n; i++) {
    int x = a[i];
    vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
    if (it == d.end())
      d.push_back(x);
    else
      *it = x;
    dp1[ind][i] = d.size();
  }
  return;
}
void func2(int ind) {
  vector<int> d;
  for (int i = ind; i >= 1; i--) {
    int x = a[i];
    vector<int>::iterator it = upper_bound(d.begin(), d.end(), x);
    if (it == d.end())
      d.push_back(x);
    else
      *it = x;
    dp2[ind][i] = d.size();
  }
  return;
}
int main() {
  int i, j, t;
  ;
  scanf("%d", &n);
  ;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    one[i] = one[i - 1];
    two[i] = two[i - 1];
    if (a[i] == 1)
      one[i]++;
    else
      two[i]++;
  }
  for (i = 1; i <= n; i++) {
    func1(i);
  }
  for (i = n; i >= 1; i--) {
    func2(i);
  }
  int ans = 0;
  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++) {
      ans = max(ans, dp1[1][i] + two[n] - two[i]);
      ans = max(ans, one[i] + dp2[j][i] + two[n] - two[j]);
      ans = max(ans, one[j] + dp1[j + 1][n]);
    }
  }
  for (i = 1; i <= n; i++) ans = max(ans, one[i] + two[n] - two[i]);
  ans = max(ans, one[n]);
  ans = max(ans, two[n]);
  printf("%d\n", ans);
  return 0;
}
