#include <bits/stdc++.h>
using namespace std;
bool siv[100002];
int primes[100002];
void sieve() {
  memset(siv, false, sizeof(siv));
  siv[0] = siv[1] = true;
  int i, j;
  for (i = 4; i <= 100000; i += 2) siv[i] = true;
  for (i = 3; i * i <= 100000; i += 2)
    if (siv[i] == false)
      for (j = i * i; j <= 100000; j += i) siv[j] = true;
  primes[0] = 0;
  primes[1] = 2;
  for (i = 3, j = 2; i < 100000; i += 2)
    if (siv[i] == false) primes[j++] = i;
}
int main() {
  long long n, i, j;
  sieve();
  cin >> n;
  if (n < 3)
    cout << 1 << endl;
  else
    cout << 2 << endl;
  for (i = 1; i <= n; i++) {
    if (!siv[i + 1])
      cout << 1 << " ";
    else
      cout << 2 << " ";
  }
}
