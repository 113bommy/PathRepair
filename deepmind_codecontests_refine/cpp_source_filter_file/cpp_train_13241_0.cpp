#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, k;
long long a[100005], v[100005];
long long ans;
vector<long long> ve;
int main() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    v[a[i]]++;
  }
  for (int i = 1; i <= 100000; i++) {
    long long x = i;
    for (int j = 1; j < k; j++) {
      x = x * i;
      if (x > 10000000000LL) break;
    }
    if (x <= 10000000000LL)
      ve.push_back(x);
    else
      break;
  }
  if (k >= 3) {
    for (int i = 1; i <= 100000; i++)
      if (v[i])
        for (int j = 0; j < ve.size() && ve[j] / i <= 100000; j++)
          if (ve[j] % i == 0) {
            int t = ve[j] / i;
            if (t < i) continue;
            if (i == t)
              ans += v[i] * (v[i] - 1) / 2;
            else
              ans += v[i] * v[t];
          }
  } else {
    for (int i = 1; i <= 100000; i++)
      if (v[i]) {
        long long x = i;
        for (int j = 2; j <= 400; j++)
          if (x % (j * j) == 0) x /= (j * j);
        for (int j = 0; j < ve.size() && ve[j] * x <= 100000; j++) {
          int t = ve[j] * x;
          if (t < i) continue;
          if (i == t)
            ans += v[i] * (v[i] - 1) / 2;
          else
            ans += v[i] * v[t];
        }
      }
  }
  cout << ans << endl;
  return 0;
}
