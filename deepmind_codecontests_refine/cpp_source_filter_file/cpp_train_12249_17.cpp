#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int mod2 = 1e9 + 9;
const long long int maxn = 2e6 + 5;
const long long int maxn1 = 1e5 + 1;
const int root = 1e6 + 5;
const long long inf = 1e18 + 18;
double pie4 = 3.1415926535;
long long int a[maxn1], b[maxn1], mn[maxn], visit[maxn];
bool prime[maxn];
vector<long long int> fac[maxn];
void sieve() {
  long long int i, j;
  for (i = 2; i < maxn; i++) {
    if (mn[i]) continue;
    mn[i] = i;
    prime[i] = true;
    for (j = i * 2; j < maxn; j += i) {
      prime[j] = false;
      mn[j] = i;
    }
  }
}
bool check(long long int no) {
  for (long long int j = 0; j < int(fac[no].size()); j++) {
    if (visit[fac[no][j]]) return false;
  }
  return true;
}
void sett(long long int no) {
  for (long long int j = 0; j < int(fac[no].size()); j++) {
    long long int x = fac[no][j];
    visit[x] = 1;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i, n, x, y, idx = -1, no = 0, j, k;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  sieve();
  for (i = 2; i <= 100000; i++) {
    x = i;
    while (x > 1) {
      y = mn[x];
      while (x % y == 0) x = x / y;
      fac[i].push_back(y);
    }
  }
  for (i = 1; i <= n; i++) {
    bool flag = true;
    for (j = 0; j < int(fac[a[i]].size()); j++) {
      if (!visit[fac[a[i]][j]]) continue;
      flag = false;
      break;
    }
    if (flag) {
      sett(a[i]);
      b[i] = a[i];
    } else {
      idx = i;
      no = a[i];
      break;
    }
  }
  if (idx != -1) {
    for (k = no + 1;; k++) {
      if (check(k)) {
        b[i] = k;
        sett(k);
        break;
      }
    }
    for (k = 2, i = idx + 1; k < maxn && i <= n; k++) {
      if (prime[k] && !visit[k]) {
        b[i] = k;
        i++;
      }
    }
  }
  for (i = 1; i <= n; i++) cout << b[i] << " ";
}
