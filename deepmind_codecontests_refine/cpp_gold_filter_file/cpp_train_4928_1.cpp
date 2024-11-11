#include <bits/stdc++.h>
using namespace std;
vector<long long int> v1, v2, v3;
string s1, s2, s3;
char s[100001];
int main() {
  long long int a[100001] = {0}, v, b[100001], c = 0, d = 0, e, f, g, h, i, j,
                k = 0, l = 0, m, n, p = 0, q, t, ct = 0, ct1 = 0, ct2 = 0,
                ck = 0, ck1 = 0, ck2 = 0, ln, ln1, start, end, mid;
  long long int a1 = 0, cnt = 0, a2 = 0, a3 = 0, a4 = 0, sum = 0, sum1 = 0,
                max1, max2, min1, min2;
  double x, y, z;
  char st[1001], ch, ch1, ch2;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    if (a[i] > a[k - 1]) c++;
  }
  if (c == m)
    cout << a[k] - a[k - 1];
  else
    cout << "0";
  return 0;
}
