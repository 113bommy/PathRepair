#include <bits/stdc++.h>
using namespace std;
long long n, aib[200002], x;
long long poz[200002];
long long lol[200002];
void update(long long aib[], long long poz, long long val) {
  for (long long i = poz; i <= n; i += (i & -i)) aib[i] += val;
}
long long query(long long aib[], long long poz) {
  long long sum = 0;
  for (long long i = poz; i; i -= (i & -i)) sum += aib[i];
  return sum;
}
long long cb(long long aib[], long long val) {
  long long ans = 0;
  long long sum = 0;
  for (long long pas = (1 << 17); pas; (pas >>= 1))
    if (ans + pas <= n && sum + aib[ans + pas] < val) {
      sum += aib[ans + pas];
      ans += pas;
    }
  return ans + 1;
}
long long gauss(long long a, long long b) {
  if (a > b) return 0;
  return 1ll * (b - a + 1) * (a + b) / 2;
}
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> x;
    poz[x] = i;
  }
  long long lmao = 0;
  for (long long i = 1; i <= n; i++) {
    update(aib, poz[i], 1);
    update(lol, poz[i], poz[i]);
    lmao += query(aib, n) - query(aib, poz[i]);
    long long poz = cb(aib, (i + 1) / 2);
    long long a = query(lol, poz), b = query(lol, n) - query(lol, poz);
    cout << gauss(poz - (i + 1) / 2 + 1, poz) - a -
                gauss(poz + 1, poz + (i - (i + 1) / 2)) + b + lmao
         << " ";
  }
  return 0;
}
