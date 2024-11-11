#include <bits/stdc++.h>
using namespace std;
string s[101];
int a[101], d[101], n, m, k, i, A, B, nx;
bool cmp1(int s1, int s2) { return s1 < s2; }
bool cmp2(int s1, int s2) { return s1 > s2; }
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> s[i];
  sort(s, s + m);
  for (i = 0; i < m; i++)
    if (!i || s[i] == s[i - 1])
      d[k]++;
    else
      d[++k]++;
  sort(d, d + k + 1, cmp2);
  sort(a, a + n, cmp1);
  for (i = 0; i <= k; i++) A += d[i] * a[i];
  sort(a, a + n, cmp2);
  for (i = 0; i <= k; i++) B += d[i] * a[i];
  cout << A << " " << B;
}
