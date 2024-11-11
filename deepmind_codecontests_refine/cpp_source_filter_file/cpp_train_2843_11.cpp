#include <bits/stdc++.h>
using namespace std;
const double INF = 1e9;
struct SuffixArray {
  int n, h;
  vector<int> lcp, sa, invsa;
  string ori;
  vector<vector<int> > rmq;
  bool cmp(int a, int b) { return invsa[a + h] < invsa[b + h]; }
  void ternary_sort(int a, int b) {
    if (a == b) return;
    int pivot = sa[a + rand() % (b - a)];
    int left = a, right = b;
    for (int i = a; i < b; i++)
      if (cmp(sa[i], pivot)) swap(sa[i], sa[left++]);
    for (int i = b - 1; i >= left; --i)
      if (cmp(pivot, sa[i])) swap(sa[i], sa[--right]);
    ternary_sort(a, left);
    for (int i = left; i < right; i++) invsa[sa[i]] = right - 1;
    if (right - left == 1) sa[left] = -1;
    ternary_sort(right, b);
  }
  SuffixArray() {}
  SuffixArray(string s) : n(s.size()), sa(n) {
    ori = s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = (int)s[i];
    ini(v);
  }
  SuffixArray(vector<int> v) : n(v.size()), sa(n) { ini(v); }
  void ini(vector<int>& v) {
    v.push_back(INT_MIN);
    for (int i = 0; i < n; i++) sa[i] = i;
    invsa = v;
    h = 0;
    ternary_sort(0, n);
    for (h = 1; h <= n; h *= 2)
      for (int j = 0, i = j; i != n; i = j)
        if (sa[i] < 0) {
          while (j < n && sa[j] < 0) j += -sa[j];
          sa[i] = -(j - i);
        } else {
          j = invsa[sa[i]] + 1;
          ternary_sort(i, j);
        }
    for (int i = 0; i < n; i++) sa[invsa[i]] = i;
    lcp.resize(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (invsa[i] > 0)
        while (v[i + res] == v[sa[invsa[i] - 1] + res]) res++;
      lcp[invsa[i]] = res;
      res = max(res - 1, 0);
    }
    int logn = __builtin_clz(1) - __builtin_clz(n);
    rmq.resize(n, vector<int>(logn + 1));
    for (int i = 0; i < n; i++) rmq[i][0] = sa[i];
    for (int l = 1; l <= logn; l++)
      for (int i = 0; i + (1 << l) <= n; i++)
        rmq[i][l] = min(rmq[i][l - 1], rmq[i + (1 << (l - 1))][l - 1]);
  }
  int operator[](int id) { return sa[id]; }
  int rmq_query(int a, int b) {
    int l = __builtin_clz(1) - __builtin_clz(b - a + 1);
    return min(rmq[a][l], rmq[b - (1 << l) + 1][l]);
  }
  inline char get(int mm, int i) {
    int p = sa[mm] + i;
    if (p >= n) return 0;
    return ori[p];
  }
  void busca(int& l, int& r, int i, const string& s) {
    int ini, fim, meio, best = n;
    ini = l, fim = r;
    while (ini <= fim) {
      int meio = (ini + fim) >> 1;
      if (get(meio, i) >= s[i])
        best = meio, fim = meio - 1;
      else
        ini = meio + 1;
    }
    ini = l, fim = r;
    l = best;
    best = -1;
    while (ini <= fim) {
      int meio = (ini + fim) >> 1;
      if (get(meio, i) <= s[i])
        best = meio, ini = meio + 1;
      else
        fim = meio - 1;
    }
    r = best;
  }
  void acha(const string& s, vector<int>& vet) {
    vet.resize(((int)(s).size()));
    int l = 0, r = n - 1;
    for (int(i) = (0); (i) < (((int)(s).size())); (i)++) {
      busca(l, r, i, s);
      if (l > r)
        vet[i] = n + 1;
      else
        vet[i] = rmq_query(l, r);
    }
  }
};
string s, sr, cur, curr;
int m, ans;
vector<int> vet, vetr;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s >> m;
  sr = s;
  reverse((sr).begin(), (sr).end());
  SuffixArray suf(s), sufr(sr);
  while (m--) {
    cin >> cur;
    curr = cur;
    reverse((curr).begin(), (curr).end());
    suf.acha(cur, vet);
    sufr.acha(curr, vetr);
    for (int(i) = (0); (i) < (((int)(cur).size())); (i)++) {
      int j = ((int)(cur).size()) - 2 - i;
      if (j >= 0 && vet[i] + i < ((int)(cur).size()) - 1 - vetr[j] - j) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}
