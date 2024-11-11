#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 1010;
int x[MAXN];
char c[MAXN][MAXN];
bool z[MAXN];
void Print(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << c[i][j];
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int lastdiff = n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    --x[i];
    if (x[i] != i)
      lastdiff = i;
    else
      z[i] = true;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) c[i][j] = '.';
  }
  if (lastdiff == -1) {
    cout << n << "\n";
    Print(n);
    return 0;
  }
  int B = n - 1;
  vector<int> pp;
  for (int e = 0; e < n; ++e) {
    if (z[e]) continue;
    bool haslast = (lastdiff == e);
    vector<int> p{e};
    int t = x[e];
    while (t != e) {
      haslast |= (lastdiff == t);
      p.push_back(t);
      t = x[t];
    }
    for (int i : p) z[i] = true;
    reverse(p.begin(), p.end());
    int maxp = 0;
    for (int i = 0; i < p.size(); ++i) {
      if (p[i] > p[maxp]) maxp = i;
    }
    reverse(p.begin(), p.begin() + maxp);
    reverse(p.begin() + maxp, p.end());
    reverse(p.begin(), p.end());
    if (haslast) {
      pp = std::move(p);
      continue;
    }
    int BB = B;
    for (int i = 0; i + 1 < p.size(); ++i) {
      int st = p[i + 1], ed = p[i];
      if (st < ed) {
        c[B][st] = '/';
        c[B][ed] = '/';
      } else {
        c[B][st] = '\\';
        c[B][ed] = '\\';
      }
      --B;
    }
    c[BB][lastdiff] = '/';
    c[B][lastdiff] = '\\';
    c[B][p.back()] = '\\';
    --B;
  }
  for (int i = 0; i + 1 < pp.size(); ++i) {
    int st = pp[i + 1], ed = pp[i];
    if (st < ed) {
      c[B][st] = '/';
      c[B][ed] = '/';
    } else {
      c[B][st] = '\\';
      c[B][ed] = '\\';
    }
    --B;
  }
  cout << n - 1 << "\n";
  Print(n);
  return 0;
}
