#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
bool flag[maxn];
int p[maxn];
int pk[maxn];
int pn;
void Getprime(int n) {
  pn = 0;
  memset(flag, false, sizeof(flag));
  int i, j;
  for (i = 2; i < n; i++) {
    if (!flag[i]) p[pn++] = i;
    for (j = 0; (j < pn) && (i * p[j] < maxn); j++) {
      flag[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}
int main() {
  int n;
  cin >> n;
  Getprime(n);
  int count = 0;
  for (int i = 0; i < pn; i++) {
    int x = p[i];
    while (x <= n) {
      x = x * p[i];
      if (x <= n) {
        pk[count++] = x;
      }
    }
  }
  cout << pn + count << endl;
  for (int i = 0; i < pn; i++) {
    cout << p[i] << " ";
  }
  for (int i = 0; i < count; i++) cout << pk[i] << " ";
  cout << endl;
  return 0;
}
