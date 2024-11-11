#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, oo = 2e9;
struct trie {
  int frq, nxt[2];
  trie() {
    frq = 0;
    memset(nxt, -1, sizeof nxt);
  }
};
int cnt;
trie t[4 * N];
void add(long long x) {
  int cur = 0;
  for (int i = 40; i >= 0; i--) {
    int b = ((1LL << i) & x) != 0;
    if (t[cur].nxt[b] == -1) {
      t[cur].nxt[b] = ++cnt;
    }
    cur = t[cur].nxt[b];
    t[cur].frq++;
  }
}
void rem(long long x) {
  int cur = 0;
  for (int i = 40; i >= 0; i--) {
    int b = ((1LL << i) & x) != 0;
    cur = t[cur].nxt[b];
    t[cur].frq--;
  }
}
long long ans = 0;
long long xr;
void get(int cur, int idx) {
  if (idx == -1) return;
  if (cur == -1) return;
  int b = ((1LL << idx) & xr) != 0;
  if (t[cur].nxt[!b] != -1 && t[t[cur].nxt[!b]].frq) {
    ans |= 1LL << idx;
    get(t[cur].nxt[!b], idx - 1);
  } else {
    get(t[cur].nxt[b], idx - 1);
  }
}
int n;
long long a[N], b[N];
int main() {
  scanf("%d", &n);
  add(0);
  long long mx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    b[i] = a[i];
    if (i) b[i] ^= b[i - 1];
    add(b[i]);
    mx = max(mx, b[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    rem(b[i]);
    xr ^= a[i];
    ans = 0;
    get(0, 40);
    mx = max(mx, ans);
  }
  cout << mx << endl;
}
