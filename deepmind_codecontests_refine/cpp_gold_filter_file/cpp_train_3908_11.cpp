#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 100;
const long double eps = 1e-12;
const long double pi = acos(-1.0L);
int myrand() { return rand(); }
unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}
int rnd(int x) { return myrand() % x; }
void precalc() {}
const int maxn = 5e5 + 100;
const int maxm = 256;
int n;
char s[maxn];
int cnt[maxn], a[maxn], na[maxn], cols[maxn], ncols[maxn], head[maxn];
int cntcols;
int where[maxn], lcp[maxn];
bool read() {
  if (scanf("%d%s", &n, s) < 2) {
    return false;
  }
  return true;
}
void solve() {
  n++;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
    cols[i] = s[i];
  }
  head[0] = 0;
  for (int i = 1; i < maxm; i++) {
    head[i] = head[i - 1] + cnt[i - 1];
  }
  for (int i = 0; i < n; i++) {
    a[head[s[i]]++] = i;
  }
  cntcols = maxm;
  for (int j = 1; j < n; j <<= 1) {
    for (int i = 0; i < cntcols; i++) {
      cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      cnt[cols[i]]++;
    }
    head[0] = 0;
    for (int i = 1; i < cntcols; i++) {
      head[i] = head[i - 1] + cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
      int k = (a[i] - j + n) % n;
      na[head[cols[k]]++] = k;
    }
    swap(a, na);
    cntcols = 1;
    ncols[a[0]] = 0;
    for (int i = 1; i < n; i++) {
      ncols[a[i]] = ncols[a[i - 1]];
      if (cols[a[i]] != cols[a[i - 1]] ||
          cols[(a[i] + j) % n] != cols[(a[i - 1] + j) % n]) {
        ncols[a[i]] = cntcols++;
      }
    }
    swap(cols, ncols);
  }
  n--;
  rotate(a, a + 1, a + n + 1);
  for (int i = 0; i < n; i++) {
    where[a[i]] = i;
  }
  for (int i = 0, k = 0; i < n; i++) {
    k = max(k - 1, 0);
    int j = where[i];
    if (j < n - 1) {
      while (s[i + k] == s[a[j + 1] + k]) {
        k++;
      }
    }
    lcp[j] = k;
  }
  for (int i = 0; i < n; i++) {
  }
  vector<int> balance(n + 1);
  vector<vector<int> > pos(2 * n + 1);
  pos[0].push_back(0);
  for (int i = 0; i < n; i++) {
    balance[i + 1] = balance[i] + (s[i] == '(' ? 1 : -1);
    pos[balance[i + 1] + n].push_back(i + 1);
  }
  vector<int> mxpos(n);
  vector<int> st;
  for (int i = n - 1; i >= 0; i--) {
    while (((int)((st).size())) && balance[st.back()] >= balance[i]) {
      st.pop_back();
    }
    mxpos[i] = (((int)((st).size())) ? st.back() : n + 1);
    st.push_back(i);
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    vector<int>& curv = pos[balance[a[i]] + n];
    int l = (int)(upper_bound(curv.begin(), curv.end(), a[i] + lcp[i]) -
                  curv.begin());
    int r = (int)(lower_bound(curv.begin(), curv.end(), mxpos[a[i]]) -
                  curv.begin());
    res += max(0, r - l);
  }
  printf(
      "%lld"
      "\n",
      res);
}
int main() {
  srand(rdtsc());
  precalc();
  while (true) {
    if (!read()) {
      break;
    }
    solve();
  }
  return 0;
}
