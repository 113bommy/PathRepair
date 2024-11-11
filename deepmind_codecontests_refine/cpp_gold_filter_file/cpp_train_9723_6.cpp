#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const long long INF64 = 1e18;
const long double EPS = 1e-12;
const long double PI = acos(-1);
const long long MD = 925262732;
const long long T = 23917;
const int N = 800101;
const int M = 1000010;
int nn, n, k, kk, type[N], a[N], b[N], p[N], L[N], R[N];
vector<pair<int, int> > pp;
vector<int> t[N];
int num(int first) {
  int l = 0, r = int((pp).size());
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (pp[m].first <= first)
      l = m;
    else
      r = m;
  }
  return pp[l].second;
}
int get(int first) {
  if (p[first] == first) return first;
  return p[first] = get(p[first]);
}
void union_set(int first, int second) {
  first = get(first);
  second = get(second);
  if (rand() & 1) swap(first, second);
  p[first] = second;
  L[second] = min(L[first], L[second]);
  R[second] = max(R[first], R[second]);
}
void merge(int v, int tl, int tr, int ind) {
  for (int i = 0; i < int(int((t[v]).size())); i++) union_set(t[v][i], k);
  t[v].clear();
  if (tl == tr) return;
  int tm = (tl + tr) / 2;
  if (ind <= tm)
    merge(v * 2, tl, tm, ind);
  else
    merge(v * 2 + 1, tm + 1, tr, ind);
}
void update(int v, int tl, int tr, int l, int r) {
  if (l > r) return;
  if (tl == l && tr == r) {
    t[v].push_back(kk);
    return;
  }
  int tm = (tl + tr) / 2;
  update(v * 2, tl, tm, l, min(r, tm));
  update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
int main() {
  cin >> nn;
  for (int i = 0; i < int(nn); i++) {
    scanf("%d %d %d", &type[i], &a[i], &b[i]);
    if (type[i] == 1) {
      pp.push_back(make_pair(a[i], 0));
      pp.push_back(make_pair(b[i], 0));
    }
  }
  sort((pp).begin(), (pp).end());
  for (int i = 0; i < int(int((pp).size())); i++) {
    if (i == 0 || pp[i].first != pp[i - 1].first) {
      n++;
      pp[i].second = n;
    } else
      pp[i].second = pp[i - 1].second;
  }
  for (int i = 0; i < int(nn); i++) {
    int first = a[i], second = b[i];
    if (type[i] == 1) {
      first = num(a[i]);
      second = num(b[i]);
      k++;
      p[k] = k;
      L[k] = first;
      R[k] = second;
      merge(1, 1, n, first);
      merge(1, 1, n, second);
      kk = get(k);
      update(1, 1, n, L[kk] + 1, R[kk] - 1);
    } else {
      first = get(first);
      second = get(second);
      if (first == second || L[second] <= L[first] && R[first] <= R[second])
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
