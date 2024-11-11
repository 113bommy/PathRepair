#include <bits/stdc++.h>
using namespace std;
int prime[168], pi = 2;
int isPrime(int a) {
  int i, s;
  s = sqrt(a);
  for (i = 0; i < pi && i < s; i++)
    if (a % prime[i] == 0) return 0;
  return 1;
}
void genPrime() {
  prime[0] = 2;
  prime[1] = 3;
  int i;
  for (i = 5; i <= 1000; i += 2)
    if (isPrime(i)) {
      prime[pi] = i;
      pi++;
    }
}
int main() {
  genPrime();
  int n, k, i, p, j, count = 0;
  cin >> n >> k;
  for (i = 0; i < 168; i++)
    if (prime[i] > n) {
      p = i - 1;
      break;
    }
  if (k > p) {
    cout << "NO" << endl;
    return 0;
  }
  for (i = p; i >= 0; i--)
    for (j = p; j > 0; j--)
      if (1 + prime[j] + prime[j - 1] == prime[i]) {
        count++;
        break;
      }
  if (count >= k)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
