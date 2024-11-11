#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 5e2;
bool sieve[maxn];
vector<int> prime;
struct bign {
  int n[3000], MOD;
  bign() {
    memset(n, 0, sizeof(n));
    MOD = 10000;
  }
  void clr() { memset(n, 0, sizeof(n)); }
  int length() {
    for (int i = 3000 - 1; i >= 0; i--)
      if (n[i] || !i) return i + 1;
  }
  bign operator*(int v) {
    bign tem;
    int lenu = min(3000, length() + 1000);
    for (int i = 0; i < lenu; i++) {
      tem.n[i] += n[i] * v;
      tem.n[i + 1] += tem.n[i] / MOD;
      tem.n[i] %= MOD;
    }
    return tem;
  }
  void pri() {
    int lenu = length();
    printf("%d", n[lenu - 1]);
    for (int i = lenu - 2; i >= 0; i--) printf("%04d", n[i]);
    puts("");
  }
};
void init();
bign last;
int main() {
  init();
  int N;
  scanf("%d", &N);
  if (N == 2) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < N - 1; i++) {
    printf("%d ", 2 * prime[i + 1]);
  }
  last.clr();
  last.n[0] = 1;
  for (int i = 1; i < N; i++) last = last * prime[i];
  last.pri();
  return 0;
}
void init() {
  for (int i = 2; i < maxn; i++)
    if (!sieve[i]) {
      prime.push_back(i);
      for (int j = i * i; j < maxn; j += i) sieve[j] = 1;
    }
}
