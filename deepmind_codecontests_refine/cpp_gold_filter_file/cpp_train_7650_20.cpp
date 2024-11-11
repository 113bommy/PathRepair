#include <bits/stdc++.h>
using namespace std;
int n, taken[1005];
int prime[1005], flag[1005];
void sieve(void) {
  int pos = 0;
  flag[1] = 1;
  prime[0] = 2;
  for (int i = 3; i < 1005; i += 2) {
    if (flag[i] == 0) {
      prime[++pos] = i;
      if (i < (1005 / i))
        for (int j = i * i; j < 1005; j += i) flag[j] = 1;
    }
  }
  return;
}
int find_pow(int val, int power) {
  int res = 1;
  while (power--) res *= val;
  return res;
}
int main() {
  sieve();
  int pos, num, cnt, val, tot = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    num = i;
    pos = 0;
    while (pos <= 167 && num > 1) {
      cnt = 0;
      while (num % prime[pos] == 0) {
        num /= prime[pos];
        cnt++;
      }
      val = find_pow(prime[pos], cnt);
      if (val > 1 && taken[val] == 0) {
        taken[val] = 1;
        tot++;
      }
      pos++;
    }
  }
  cout << tot << endl;
  for (int i = 2; i <= n; i++)
    if (taken[i]) cout << i << " ";
  return 0;
}
