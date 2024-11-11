#include <bits/stdc++.h>
using namespace std;
int n;
int a[105];
int prime[100005] = {0};
bool vst[100005] = {0};
int ans;
map<int, int> sg;
void getprime() {
  for (int i = 2; i <= 100000; i++)
    if (!vst[i]) {
      prime[0]++;
      prime[prime[0]] = i;
      for (int j = i + i; j <= 100000; j += i) vst[j] = 1;
    }
}
int getsg(int num) {
  if (num == 0) return 0;
  if (sg.count(num)) return sg[num];
  map<int, int> vis;
  int ge = 0, tmpnum = num;
  while (tmpnum) {
    tmpnum /= 2;
    ge++;
  }
  for (int i = 1; i <= ge; i++)
    vis[getsg((num >> i) | (num & ((1 << (i - 1)) - 1)))] = 1;
  for (int i = 0;; i++)
    if (vis[i] == 0) return sg[num] = i;
}
int getans(int p) {
  int lyg[35] = {0};
  for (int i = 1; i <= n; i++) {
    int num = 0;
    while (a[i] % p == 0) {
      a[i] /= p;
      num++;
    }
    if (num != 0) lyg[num] = 1;
    lyg[0] = max(lyg[0], num);
  }
  int nowstate = 0;
  for (int i = lyg[0]; i >= 1; i--) nowstate = 2 * nowstate + lyg[i];
  return getsg(nowstate);
}
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= prime[0] && prime[j] <= a[i]; j++) {
      if (a[i] % prime[j] == 0) ans ^= getans(prime[j]);
    }
  }
  for (int i = 1; i <= n; i++)
    if (a[i] != 1) ans ^= getans(a[i]);
  if (ans == 0)
    printf("Arpa\n");
  else
    printf("Mojtaba\n");
}
int main() {
  getprime();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  solve();
  return 0;
}
