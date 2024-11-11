#include <bits/stdc++.h>
using namespace std;
int PrimeNum;
bool is_prime[4000005];
int prime[4000005];
long long factorial[200005];
void init(long long p) {
  PrimeNum = 0;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < 4000005; i++) is_prime[i] = true;
  for (int i = 2; i < 4000005; i++)
    if (is_prime[i]) {
      PrimeNum++;
      prime[PrimeNum] = i;
      for (int j = i * 2; j < 4000005; j += i) is_prime[j] = false;
    }
  factorial[0] = factorial[1] = 1;
  for (int i = 2; i < 200005; i++) factorial[i] = factorial[i - 1] * i % p;
}
long long a[200005], vis[4000005], b[200005];
int main() {
  ios::sync_with_stdio(false);
  init(2);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int eq = 1, k = 0;
  for (int i = 1; i <= n; i++) {
    long long x = a[i];
    int j = 1;
    if (is_prime[x]) {
      if (!vis[x])
        vis[x] = 1;
      else {
        eq = 0;
        break;
      }
    } else {
      while (x > 1) {
        while (x % prime[j] == 0) {
          x /= prime[j];
          if (vis[prime[j]]) {
            eq = 0;
            break;
          }
        }
        if (vis[x]) {
          eq = 0;
          break;
        }
        if (eq == 0) break;
        if (is_prime[x]) {
          x = 1;
        }
        j++;
      }
      if (eq == 0)
        break;
      else {
        x = a[i];
        j = 1;
        while (x > 1) {
          while (x % prime[j] == 0) {
            x /= prime[j];
            vis[prime[j]] = 1;
          }
          if (is_prime[x]) {
            vis[x] = 1;
            x = 1;
          }
          j++;
        }
      }
    }
    k++;
    b[k] = a[i];
  }
  if (eq == 0) {
    int e = 0, f, m = 1e9;
    for (int i = a[k + 1]; i <= 100000; i++) {
      int x = i;
      int j = 1;
      int flag = 1;
      while (x > 1) {
        while (x % prime[j] == 0) {
          x /= prime[j];
          if (vis[prime[j]]) {
            flag = 0;
            break;
          }
        }
        if (vis[x]) {
          flag = 0;
          break;
        }
        if (flag == 0) break;
        j++;
      }
      if (flag) {
        k++;
        b[k] = i;
        x = i;
        j = 1;
        while (x > 1) {
          while (x % prime[j] == 0) {
            x /= prime[j];
            vis[prime[j]] = 1;
          }
          j++;
        }
        break;
      }
    }
    int pre = 1;
    for (k = k + 1; k <= n; k++) {
      for (int j = pre; j <= PrimeNum; j++) {
        if (!vis[prime[j]]) {
          vis[prime[j]] = 1;
          b[k] = prime[j];
          pre = j + 1;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
}
