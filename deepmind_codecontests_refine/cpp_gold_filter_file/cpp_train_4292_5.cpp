#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;
const int MAXN = 1000;
int prime[MAXN + 1];
void getPrime() {
  memset(prime, 0, sizeof(prime));
  for (int i = 2; i <= MAXN; i++) {
    if (!prime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  getPrime();
  for (int te = 0; te < t; te++) {
    int n;
    cin >> n;
    int res[3];
    int flag = 0;
    for (int i = 2; i <= 10000; i++) {
      if (n % i != 0) {
        continue;
      } else {
        int temp = n / i;
        for (int j = i + 1; j <= 10000; j++) {
          if (temp % j != 0) {
            continue;
          } else if (temp / j <= j) {
            break;
          } else {
            res[0] = i;
            res[1] = j;
            res[2] = temp / res[1];
            flag = 1;
            break;
          }
        }
        if (flag == 1) {
          break;
        }
      }
    }
    if (flag == 1) {
      cout << "YES"
           << "\n";
      cout << res[0] << " " << res[1] << " " << res[2] << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
  return 0;
}
