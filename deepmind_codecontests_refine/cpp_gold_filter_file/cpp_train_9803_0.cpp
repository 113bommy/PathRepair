#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int isprime[maxn];
int prime[maxn];
int ans[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= maxn; i++) isprime[i] = 1;
  for (int i = 2; i * i <= maxn; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= maxn; j += i) isprime[j] = 0;
    }
  }
  int cnt = 0;
  for (int i = 0; i <= maxn; i++)
    if (isprime[i]) {
      prime[cnt++] = i;
    }
  int num = 0;
  for (int i = 2; i <= n; i++) {
    if (isprime[i])
      ans[i] = ++num;
    else {
      for (int j = 0; j <= cnt; j++)
        if (i % prime[j] == 0) {
          ans[i] = j + 1;
          break;
        }
    }
  }
  for (int i = 2; i <= n; i++) {
    cout << ans[i];
    if (i < n) cout << ' ';
  }
  cout << endl;
  return 0;
}
