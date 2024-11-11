#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 100;
const long long lINF = 1e18;
const double EPS = 1e-12;
long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}
int myrand() { return rand(); }
int rnd(int x) { return myrand() % x; }
const int maxn = 1e6 + 100;
int n;
int a[maxn];
int go[maxn], pre[maxn];
bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}
void solve() {
  int ans = 1;
  {
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
      cnt0 += (a[i] == 0);
    }
    ans = max(ans, cnt0);
  }
  sort(a, a + n);
  memset(go, -1, sizeof(go));
  memset(pre, -1, sizeof(pre));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int k = (int)(lower_bound(a, a + n, a[i] + a[j]) - a);
      if (k < n && a[k] == a[i] + a[j]) {
        go[i * n + j] = j * n + k;
        pre[j * n + k] = i * n + j;
      }
    }
  }
  vector<int> as;
  for (int i = 0; i < n; i++) {
    as.push_back(a[i]);
  }
  sort(as.begin(), as.end());
  as.resize(unique(as.begin(), as.end()) - as.begin());
  for (int i = 0; i < n; i++) {
    a[i] = (int)(lower_bound(as.begin(), as.end(), a[i]) - as.begin());
  }
  int zero = (int)(find(as.begin(), as.end(), 0) - as.begin());
  vector<int> cnt(2000);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  vector<int> curcnt(2000);
  for (int i = 0; i < n * n; i++) {
    int x = i / n, y = i % n;
    if (y == x) {
      continue;
    }
    if (a[x] == zero && a[y] == zero) {
      continue;
    }
    if (pre[i] != -1) {
      continue;
    }
    vector<int> num;
    num.push_back(a[x]);
    num.push_back(a[y]);
    ans = max(ans, 2);
    curcnt[a[x]]++;
    curcnt[a[y]]++;
    for (int i = 2, j = 0;; i++) {
      int nxt = go[x * n + y];
      if (nxt == -1) {
        break;
      }
      int z = nxt % n;
      curcnt[a[z]]++;
      if (curcnt[a[z]] > cnt[a[z]]) {
        while (1) {
          curcnt[num[j]]--;
          j++;
          if (num[j - 1] == a[z]) {
            break;
          }
        }
      }
      ans = max(ans, i - j + 1);
      x = y, y = z;
      num.push_back(a[z]);
    }
    for (int i = 0; i < ((int)((num).size())); i++) {
      curcnt[num[i]] = 0;
    }
  }
  printf("%d\n", ans);
}
int main() {
  srand(rdtsc());
  while (true) {
    if (!read()) {
      break;
    }
    solve();
  }
  return 0;
}
