#include <bits/stdc++.h>
using namespace std;
vector<int> pr;
struct Mas {
  int mass[10000];
};
int a[2001];
Mas okey[5000], cnt;
unsigned long long key[5000];
void go(int x, int k) {
  for (int i = 0; i < (int)pr.size(); i++)
    while (x % pr[i] == 0) {
      x /= pr[i];
      cnt.mass[i] += k;
    }
  if (x != 1) {
    pr.push_back(x);
    cnt.mass[pr.size()] = 1;
  }
}
unsigned long long C(int n, int k) {
  if (n > 0) cnt = okey[n - 1];
  int xx = n;
  if (n < k) swap(n, k);
  for (int i = n - k + 1; i <= n; i++) go(i, 1);
  for (int i = 2; i <= k; i++) go(i, -1);
  okey[xx] = cnt;
  unsigned long long ans = 1;
  for (int i = 0; i < (int)pr.size(); i++)
    for (int j = 0; j < cnt.mass[i]; j++) ans = (ans * pr[i]) % 1000000007;
  return ans;
}
unsigned long long CC(int n, int k) {
  if (n > 0) cnt = okey[n - 1];
  int xx = n;
  if (n < k) swap(n, k);
  for (int i = n; i <= n; i++) go(i, 1);
  for (int i = max(k, 2); i <= k; i++) go(i, -1);
  okey[xx] = cnt;
  unsigned long long ans = 1;
  for (int i = 0; i < (int)pr.size(); i++)
    for (int j = 0; j < cnt.mass[i]; j++) ans = (ans * pr[i]) % 1000000007;
  return ans;
}
int main() {
  for (int i = 2; i * i <= 1000000000; i++) {
    bool f = true;
    for (int j = 0; j < (int)pr.size(); j++)
      if (i % pr[j] == 0) {
        f = false;
        break;
      }
    if (f) pr.push_back(i);
  }
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (k == 0) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
  }
  key[0] = C(0, k - 1);
  for (int i = n - 2; i >= 0; i--)
    key[n - 1 - i] = CC(n - 1 - i, k - 1 + (n - 1 - i));
  for (int i = 0; i < n; i++) {
    unsigned long long ans = 0;
    for (int j = 0; j <= i; j++) ans = (ans + a[j] * key[i - j]) % 1000000007;
    printf("%I64d ", ans);
  }
  return 0;
}
