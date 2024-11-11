#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
int nxt[100100];
bool sieve[100100];
int m[10][10];
long long a = 0;
void erathostenes() {
  sieve[0] = true;
  sieve[1] = true;
  for (int i = 2; i * i < 100000; i++) {
    for (int j = i * i; j < 100000; j += i) {
      sieve[j] = true;
    }
  }
}
void print(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) printf("%d", m[i][j]);
    printf("\n");
  }
  printf("\n");
}
bool check(int n, int r) {
  int t = 1;
  int c = 0;
  for (int i = n - 1; i >= 0; i--) {
    c += m[r][i] * t;
    t = t * 10;
  }
  if (!sieve[c]) return true;
  return false;
}
bool f(int n, int l, int t) {
  if (l == n) {
    return true;
  }
  for (int i = l; i < n; i++) m[l][i] = 0;
  int s = 0, e = 1, c;
  for (int i = 0; i < n; i++) s = s * 10 + m[l][i];
  for (int i = l; i < n; i++) e *= 10;
  e += s;
  s = nxt[s];
  if (!sieve[e]) e++;
  e = nxt[e];
  if (s == e) return false;
  for (int i = s; i < e; i++) {
    c = primes[i];
    for (int j = n - 1; j >= l; j--) {
      m[l][j] = c % 10;
      m[j][l] = c % 10;
      c = c / 10;
    }
    if (f(n, l + 1, t)) a++;
  }
  return false;
}
int main() {
  int t, n, l, c;
  erathostenes();
  scanf("%d", &t);
  for (int i = 2; i <= 100000; i++) {
    if (!sieve[i - 1])
      nxt[i] = nxt[i - 1] + 1, primes.push_back(i - 1);
    else
      nxt[i] = nxt[i - 1];
  }
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    c = n;
    while (c != 0) {
      l++;
      c = c / 10;
    }
    for (int j = l - 1; j >= 0; j--) {
      m[0][j] = n % 10;
      m[j][0] = m[0][j];
      n = n / 10;
    }
    f(l, 1, i);
    printf("%lld\n", a);
    a = 0;
    l = 0;
  }
}
