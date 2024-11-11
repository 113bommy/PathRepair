#include <bits/stdc++.h>
using namespace std;
int inf = 1000000000;
int data[100005];
int ada[2005];
int n, k, x;
map<long long, int> dah;
long long mod = 999999999989LL;
void urut() {
  memset(ada, 0, sizeof(ada));
  for (int(i) = (0); (i) <= (n - 1); ++(i)) ++ada[data[i]];
  int now = 0;
  for (int(i) = (0); (i) <= (2000); ++(i)) {
    while (ada[i]--) data[now++] = i;
  }
}
int main() {
  scanf("%d %d %d", &n, &k, &x);
  for (int(i) = (0); (i) <= (n - 1); ++(i)) scanf("%d", &data[i]);
  urut();
  for (int(i) = (1); (i) <= (k); ++(i)) {
    for (int j = 0; j < n; j += 2) data[j] ^= x;
    urut();
    long long hsh = 0;
    for (int(j) = (0); (j) <= (n - 1); ++(j)) {
      hsh = (hsh * n + data[j]) % mod;
    }
    if (dah.count(hsh)) {
      int sisa = k - i;
      int len = i - dah[hsh];
      sisa %= len;
      while (sisa--) {
        for (int j = 0; j < n; j += 2) data[j] ^= x;
        urut();
      }
      printf("%d %d\n", data[n - 1], data[0]);
      return 0;
    }
    dah[hsh] = i;
  }
  printf("%d %d\n", data[n - 1], data[0]);
}
