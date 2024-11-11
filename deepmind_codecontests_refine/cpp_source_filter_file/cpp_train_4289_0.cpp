#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
int n;
long long int k, fat[MAX], tmp[MAX];
vector<long long int> lk;
int lucky(long long int x) {
  while (x > 0LL) {
    long long int a = (x % 10LL);
    if (a != 4LL && a != 7LL) return 0;
    x /= 10LL;
  }
  return 1;
}
void lk_gen(int pos) {
  if (pos == 9) {
    bool allzero = true, valido = true;
    for (int i = 0; i < 9; i++) {
      if (tmp[i] != 0LL) allzero = false;
      if (tmp[i] == 0LL && allzero == false) valido = false;
    }
    if (allzero || !valido) return;
    long long int x = 0LL, base = 1LL;
    for (int i = 8; i >= 0; i--) {
      x += (tmp[i] * base);
      base *= 10LL;
    }
    lk.push_back(x);
    return;
  }
  tmp[pos] = 0LL;
  lk_gen(pos + 1);
  tmp[pos] = 4LL;
  lk_gen(pos + 1);
  tmp[pos] = 7LL;
  lk_gen(pos + 1);
  return;
}
void solve(int ini) {
  long long int cnt = k, v[20];
  int jump, ans = 0;
  for (int i = 0; i < n - ini + 1; i++) v[i] = i + ini;
  for (int i = ini; i <= n; i++) {
    jump = 1;
    while (fat[n - i] < cnt) {
      swap(v[i - ini], v[i + jump - ini]);
      jump++;
      cnt -= fat[n - i];
    }
  }
  for (int i = 0; i < n - ini + 1; i++)
    if (lucky(i + ini) && lucky(v[i])) ans++;
  for (int i = (int)lk.size() - 1; i >= 0; i--) {
    if (lk[i] < ini) {
      ans += i + 1;
      break;
    }
  }
  printf("%d\n", ans);
}
int main() {
  scanf(" %d %lld", &n, &k);
  fat[0] = 1;
  for (int i = 1; i <= 13; i++) fat[i] = (long long int)i * fat[i - 1];
  lk.clear();
  lk_gen(0);
  if (n <= 13 && fat[n] < k)
    printf("-1\n");
  else {
    int ini;
    for (ini = n; ini >= 0; ini--)
      if (fat[n - ini + 1] > k) break;
    solve(ini);
  }
  return 0;
}
