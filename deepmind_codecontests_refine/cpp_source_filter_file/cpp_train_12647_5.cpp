#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mx = 5e5;
vector<int> fc(mx + 1);
vector<int> pi(mx + 1, -1);
void init() {
  for (int i = 2; i <= mx; i += 2) fc[i] = 2;
  for (LL j = 3; j <= mx; j++) {
    if (fc[j]) continue;
    fc[j] = j;
    for (LL i = j * j; i <= mx; i += 2 * j)
      if (!fc[i]) fc[i] = j;
  }
  int cur = 0;
  for (int i = 2; i <= mx; i++) {
    if (fc[i] == i) pi[i] = cur++;
  }
}
vector<int> frq(mx + 1);
int cur = 0;
void add(int m, int v) {
  int factors[16];
  int fsiz = 0;
  for (int j; fc[m];) {
    j = fc[m];
    factors[fsiz++] = j;
    while (!(m % j)) m /= j;
  }
  for (int s = 0; s < (1 << fsiz); s++) {
    int a = 1;
    for (int k = 0, t = s; t; t >>= 1, k++)
      if (t & 1) a *= factors[k];
    frq[a] += v;
  }
}
int query(int m) {
  int r = 0;
  int factors[16];
  int fsiz = 0;
  for (int j; fc[m];) {
    j = fc[m];
    factors[fsiz++] = j;
    while (!(m % j)) m /= j;
  }
  for (int s = 0; s < (1 << fsiz); s++) {
    int a = 1, num = 0;
    for (int k = 0, t = s; t; t >>= 1, k++)
      if (t & 1) {
        a *= factors[k];
        num++;
      }
    r += (num & 1 ? -1 : 1) * frq[a];
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  init();
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<bool> insh(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  for (int i = 0; i < (q); i++) {
    int x;
    cin >> x, x--;
    int num = a[x];
    if (insh[x]) {
      add(num, -1);
      cur -= query(num);
    } else {
      cur += query(num);
      add(num, 1);
    }
    insh[x] = !insh[x];
    cout << cur << '\n';
  }
}
