#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000500;
int criba[MAXN];
void buildS() {
  for (int i = 2; i * i < MAXN; i++)
    if (!criba[i])
      for (int j = i * i; j < MAXN; j += i + i) criba[j] = i;
}
long long cant(int n, int r) { return n / 9 + (1 <= r && r <= n % 9 ? 1 : 0); }
long long getall(int n) {
  long long ans = 0;
  for (int a = (0); a < (int)(9); a++)
    for (int b = (0); b < (int)(9); b++) {
      int c = a * b % 9;
      long long act = cant(n, a) * cant(n, b) * cant(n, c);
      ans += act;
    }
  return ans;
}
map<int, int> F;
void fact(int n) {
  F.clear();
  while (criba[n]) {
    int p = criba[n];
    F[p]++;
    n /= p;
  }
  if (n > 1) F[n]++;
}
long long cantdiv() {
  long long ans = 1;
  for (pair<int, int> t : F) ans *= (t.second + 1);
  return ans;
}
long long getgood(int n) {
  long long ans = 0;
  for (int i = (1); i < (int)(n + 1); i++) {
    fact(i);
    long long act = cantdiv();
    ans += act;
  }
  return ans;
}
int n;
int main() {
  buildS();
  while (scanf("%d", &n) >= 1) {
    long long tot = getall(n);
    long long good = getgood(n);
    printf("%lld\n", tot - good);
  }
  return 0;
}
