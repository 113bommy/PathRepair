#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<int, int>;
void xmax(int& a, int b) { a = max(a, b); }
void xmin(int& a, int b) { a = min(a, b); }
void print(vc<int>& a, string second) {
  cerr << "prinitng " << second << "\n";
  for (int i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
int b = 21;
vc<vc<int> > par;
int find_place(int anz, int cur) {
  for (int i = b - 1; i >= 0; i--) {
    if (anz >= (1 << i)) {
      anz -= (1 << i);
      if (cur < 0)
        cur -= (1 << i);
      else
        cur = par[cur][i];
    }
  }
  return cur;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string second;
  cin >> second;
  int n = second.size();
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int k, d;
    cin >> k >> d;
    par = vc<vc<int> >(k + 1, vc<int>(b));
    int krat = 0;
    for (int i = 0; i < d; i++) {
      for (int j = i; j < k; j += d) {
        par[j + 1][0] = krat;
        krat++;
      }
    }
    par[0][0] = -1;
    for (int i = 1; i < b; i++) {
      for (int j = -1; j < k; j++) {
        if (par[j + 1][i - 1] < 0)
          par[j + 1][i] = par[j + 1][i - 1] - (1 << (i - 1));
        else
          par[j + 1][i] = par[par[j + 1][i - 1]][i - 1];
      }
    }
    vc<int> place(n);
    for (int i = 0; i < k; i++) {
      int kann = (n - k) + 1;
      int wo = find_place(kann, i + 1);
      place[i] = wo + n - k + 1;
    }
    for (int j = 0; j + k < n; j++) {
      int kann = n - k - j;
      int wo = find_place(kann, k);
      place[j + k] = wo + n - k + 1;
    }
    vc<char> res(n, '?');
    for (int i = 0; i < n; i++) {
      res[place[i] - 1] = second[i];
    }
    for (int i = 0; i < n; i++) {
      cout << res[i];
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
      second[i] = res[i];
    }
  }
}
