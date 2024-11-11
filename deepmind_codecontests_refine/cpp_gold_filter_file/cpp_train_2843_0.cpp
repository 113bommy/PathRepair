#include <bits/stdc++.h>
using namespace std;
const int tam = 10000010;
struct node {
  int mini, izq, der;
  node() { izq = 1000000007, der = -1; }
};
node join(node b, node c) {
  node a;
  a.mini = min(b.mini, c.mini);
  a.izq = min(b.izq, c.izq);
  a.der = max(b.der, c.der);
  return a;
}
vector<int> sa, lcp;
int nn;
node t[1000000];
void init(int b, int e, int node) {
  if (b == e) {
    if (sa[e] < nn) t[node].izq = t[node].der = sa[b];
    t[node].mini = lcp[b];
    return;
  }
  int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
  init(b, mid, l);
  init(mid + 1, e, r);
  t[node] = join(t[l], t[r]);
}
node query(int b, int e, int node, int i, int j) {
  if (b >= i && e <= j) return t[node];
  int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
  if (mid < i) return query(mid + 1, e, r, i, j);
  if (mid >= j) return query(b, mid, l, i, j);
  return join(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
string asd;
bool cmp(int a, int b) { return asd[a] < asd[b]; }
void suffixa(string &second) {
  int n = second.size(), ax, cc;
  vector<int> sa1(n), col(n), col1(n), head(n);
  sa.resize(n);
  asd = second;
  for (int i = 0; i < n; i++) sa[i] = i;
  stable_sort(sa.begin(), sa.end(), cmp);
  col[sa[0]] = head[0] = cc = 0;
  for (int i = 1; i < n; i++) {
    if (second[sa[i]] != second[sa[i - 1]]) cc++, head[cc] = i;
    col[sa[i]] = cc;
  }
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i++) {
      ax = (sa[i] - k + n) % n;
      sa1[head[col[ax]]++] = ax;
    }
    sa = sa1;
    col1[sa[0]] = head[0] = cc = 0;
    for (int i = 1; i < n; i++) {
      if (col[sa[i]] != col[sa[i - 1]] ||
          col[(sa[i] + k) % n] != col[(sa[i - 1] + k) % n])
        cc++, head[cc] = i;
      col1[sa[i]] = cc;
    }
    col = col1;
  }
}
void build_lcp(string &second) {
  int n = second.size(), z = 0, k;
  vector<int> sa1(n);
  lcp.assign(n, 0);
  for (int i = 0; i < n; i++) sa1[sa[i]] = i;
  for (int i = 0; i < n; i++) {
    k = sa1[i];
    while (k < n - 1 && second[i + z] == second[sa[k + 1] + z]) z++;
    lcp[k] = z;
    z = max(z - 1, 0);
  }
}
int table[22][300000];
void sparce() {
  for (int i = 0; i < lcp.size(); i++) table[0][i] = lcp[i];
  int n = lcp.size(), ac = n;
  for (int k = 1, i = 1; k < n; k *= 2, i++) {
    for (int j = 0; j < ac - k; j++)
      table[i][j] = min(table[i - 1][j], table[i - 1][j + k]);
    ac -= k;
  }
}
int querys(int b, int e) {
  int lev = (int)(log2(e - b + 1) + 1e-9);
  return min(table[lev][b], table[lev][e - (1 << lev) + 1]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string second;
  cin >> second;
  nn = second.size();
  int ta;
  cin >> ta;
  string ar[ta];
  for (int i = 0; i < ta; i++) {
    cin >> ar[i];
    second += '#' + ar[i];
  }
  second += '$';
  suffixa(second);
  build_lcp(second);
  int tata = second.size();
  init(0, tata - 1, 0);
  sparce();
  int res = 0;
  vector<int> sa1(tata);
  for (int i = 0; i < tata; i++) sa1[sa[i]] = i;
  int lef = nn + 1;
  int lo, hi, mid, rer, rel, fro, inl, inr;
  for (int i = 0; i < ta; i++) {
    for (int j = 1; j < ar[i].size(); j++) {
      if (ar[i].size() > nn) break;
      lo = sa1[lef], hi = tata - 1, rer = sa1[lef];
      fro = lo;
      while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (querys(fro, mid) >= j)
          rer = mid, lo = mid + 1;
        else
          hi = mid - 1;
      }
      lo = 0, hi = sa1[lef] - 1, rel = sa1[lef];
      fro = hi;
      while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (querys(mid, fro) >= j)
          rel = mid, hi = mid - 1;
        else
          lo = mid + 1;
      }
      int rel1 = rel, rer1 = rer;
      inl = query(0, tata - 1, 0, rel, rer + (lcp[rer] >= j ? 1 : 0)).izq;
      lo = sa1[lef + j], hi = tata - 1, rer = sa1[lef + j];
      fro = lo;
      while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (querys(fro, mid) >= ar[i].size() - j)
          rer = mid, lo = mid + 1;
        else
          hi = mid - 1;
      }
      lo = 0, hi = sa1[lef + j] - 1, rel = sa1[lef + j];
      fro = hi;
      while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (querys(mid, fro) >= ar[i].size() - j)
          rel = mid, hi = mid - 1;
        else
          lo = mid + 1;
      }
      inr = query(0, tata - 1, 0, rel,
                  rer + (lcp[rer] >= ar[i].size() - j ? 1 : 0))
                .der;
      if (inl + j <= inr) {
        res++;
        break;
      }
    }
    lef += ar[i].size() + 1;
  }
  cout << res << '\n';
  return 0;
}
