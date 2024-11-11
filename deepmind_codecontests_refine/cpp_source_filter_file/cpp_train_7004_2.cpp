#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
bool cmax(T& a, const U& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
bool cmin(T& a, const U& b) {
  return b < a ? a = b, 1 : 0;
}
void _BG(const char* s) { cerr << s << endl; }
template <class T, class... TT>
void _BG(const char* s, T a, TT... b) {
  for (size_t c = 0; *s && (c || *s != ','); cerr << *s++)
    c += count(begin("([{"), end("([{"), *s) -
         count(begin(")]}"), end(")]}"), *s);
  cerr << " = " << a;
  if (*s) {
    cerr << ", ";
    ++s;
  }
  _BG(s, b...);
}
const int MOD = 998244353;
const int N = 2e5 + 87;
int pa[N], sz[N], hb[N], po[N];
int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
void meld(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  sz[a] += sz[b];
  pa[b] = a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<bool> inb(n + 1);
    vector<int> b(k);
    for (int& x : b) {
      cin >> x;
      inb[x] = 1;
    }
    iota(pa, pa + n, 0);
    fill_n(sz, n, 1);
    fill_n(hb, n, 0);
    for (int i = 0; i < n; ++i) {
      po[a[i]] = i;
      if (inb[a[i]]) {
        hb[i] = 1;
        continue;
      }
      if (i && !inb[a[i - 1]]) meld(i - 1, i);
    }
    long long ans = 1;
    for (int i = 0; i < k; ++i) {
      int j = po[b[i]];
      long long c = 0;
      int l = j, r = j;
      if (j - 1 >= 0 && sz[find(j - 1)] && !hb[find(j - 1)]) {
        l = find(j - 1);
        ++c;
      }
      if (j + 1 < n && sz[r = find(j + 1)] && !hb[find(j + 1)]) {
        r = find(j + 1);
        ++c;
      }
      ans = ans * c % MOD;
      meld(l, j);
      meld(r, j);
      sz[find(j)]--;
      hb[find(j)] = 0;
    }
    cout << ans << '\n';
  }
}
