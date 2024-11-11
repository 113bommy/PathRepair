#include <bits/stdc++.h>
using namespace std;
void FastInputOutput() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void ReadFromFile() { freopen("in.txt", "r", stdin); }
int D() {
  int t;
  scanf("%d", &t);
  return t;
}
long long LLD() {
  long long t;
  scanf("%lld", &t);
  return t;
}
char C() {
  char c;
  scanf("%c", &c);
  return c;
}
const int N = 2e5 + 5;
vector<pair<int, int> > a[N];
vector<int> mi[N];
bool cpm(pair<int, int> s, pair<int, int> f) { return (f.first > s.first); }
int main() {
  int TCF = 1;
  ;
  while (TCF--) {
    int n = D(), x = D();
    for (int i = 0; i < n; ++i) {
      int l = D(), r = D(), c = D();
      if (r - l + 1 > x) continue;
      a[r - l + 1].push_back({l, c});
    }
    for (int i = 0; i < N; ++i) {
      sort(a[i].begin(), a[i].end(), cpm);
      int sz = a[i].size();
      if (!sz) continue;
      vector<int> m(a[i].size());
      m[sz - 1] = a[i][sz - 1].second;
      for (int j = sz - 2; j >= 0; --j) m[j] = min(m[j + 1], a[i][j].second);
      mi[i] = m;
    }
    int ans = INT_MAX;
    for (int len = 1; len < x; ++len) {
      for (int i = 0; i < a[len].size(); ++i) {
        int l = a[len][i].first, r = l + len - 1, c = a[len][i].second;
        int left = x - len;
        pair<int, int> t = {r, 0};
        int idx = upper_bound(a[left].begin(), a[left].end(), t, cpm) -
                  a[left].begin();
        if (a[left].size() != idx)
          ans = min(ans, mi[left][idx] + c);
        else
          break;
      }
    }
    printf("%d\n", ans == INT_MAX ? -1 : ans);
  }
  return 0;
}
