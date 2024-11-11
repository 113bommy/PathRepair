#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int N = 100005;
const double PI = 4 * atan(1);
const double eps = 1e-7;
const long long oo = 1e10;
const int K = 26;
vector<int> sort_cyclic_shifts(string const& s) {
  int n = s.size();
  const int alphabet = 256;
  vector<int> p(n), c(n), cnt((alphabet > n ? alphabet : n), 0);
  for (int i = 0; i < n; i++) cnt[s[i]]++;
  for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i - 1]]) classes++;
    c[p[i]] = classes - 1;
  }
  vector<int> pn(n), cn(n);
  for (int h = 0; (1 << h) < n; ++h) {
    for (int i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) pn[i] += n;
    }
    fill(cnt.begin(), cnt.begin() + classes, 0);
    for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
    for (int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; i++) {
      pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
      pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
      if (cur != prev) ++classes;
      cn[p[i]] = classes - 1;
    }
    c.swap(cn);
  }
  return p;
}
vector<int> suffix_array_construction(string s) {
  s += "$";
  vector<int> sorted_shifts = sort_cyclic_shifts(s);
  sorted_shifts.erase(sorted_shifts.begin());
  return sorted_shifts;
}
vector<int> lcp_construction(string const& s, vector<int> const& p) {
  int n = s.size();
  vector<int> rank(n, 0);
  for (int i = 0; i < n; i++) rank[p[i]] = i;
  int k = 0;
  vector<int> lcp(n - 1, 0);
  for (int i = 0; i < n; i++) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = p[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    lcp[rank[i]] = k;
    if (k) k--;
  }
  return lcp;
}
string s;
long long k;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  int n = s.size();
  cin >> k;
  if (k > n * (n + 1) / 2) {
    cout << "No such line.";
    return 0;
  }
  vector<int> p = suffix_array_construction(s);
  vector<int> lcp = lcp_construction(s, p);
  int st = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      st = 0;
    } else {
      st = lcp[i - 1];
    }
    while (st < n - p[i] && k) {
      int j = i;
      k--;
      while (j < n - 1 && lcp[j] > st && k) {
        j++;
        k--;
        if (k == 0) break;
      }
      if (k == 0) break;
      st++;
    }
    if (k == 0) {
      for (int o = p[i]; o <= p[i] + st; o++) {
        cout << s[o];
      }
      return 0;
    }
  }
  return 0;
}
