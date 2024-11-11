#include <bits/stdc++.h>
using namespace std;
long long a[511];
long long a1[1010];
bool u[511];
long long s[500];
long long pos[500];
int main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  long long uk = 1;
  long long uk1 = 0;
  for (long long i = 1; i <= m; i++) {
    cin >> a1[i];
    if (!u[a1[i]]) {
      u[a1[i]] = 1;
      pos[a1[i]] = uk;
      s[a1[i]] = s[uk1] + a[uk1];
      uk1 = a1[i];
      uk++;
    }
  }
  for (long long i = 1; i <= m; i++) {
    long long q = a1[i];
    ans += s[q];
    for (long long j = 1; j <= n; j++) {
      if (pos[q] > pos[j]) {
        pos[j]++;
        s[j] += a[q];
      }
    }
    s[q] = 0;
    pos[q] = 1;
  }
  cout << ans;
  return 0;
}
