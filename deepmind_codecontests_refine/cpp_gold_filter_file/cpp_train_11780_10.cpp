#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const long long LINF = (long long)INF * INF;
const int MAX = 200 * 1000 + 7;
const int LOG = 18;
int p[MAX];
int a[MAX];
int invP[MAX];
vector<int> positions[MAX];
int ptr[MAX];
int par[LOG][MAX];
int ST[LOG][MAX];
int lg[MAX];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = (0); i < (n); ++i) {
    scanf("%d", p + i);
    p[i]--;
    invP[p[i]] = i;
  }
  for (int i = (0); i < (m); ++i) {
    scanf("%d", a + i);
    a[i]--;
    positions[a[i]].push_back(i);
  }
  for (int i = (0); i < (m); ++i) {
    ptr[a[i]]++;
    int pos = invP[a[i]] + 1;
    if (pos == n) {
      pos = 0;
    }
    par[0][i] = ptr[p[pos]] < (int)((positions[p[pos]]).size())
                    ? positions[p[pos]][ptr[p[pos]]]
                    : m;
  }
  par[0][m] = m;
  for (int j = (1); j < (LOG); ++j) {
    for (int i = (0); i < (m + 1); ++i) {
      par[j][i] = par[j - 1][par[j - 1][i]];
    }
  }
  for (int i = (0); i < (m); ++i) {
    ST[0][i] = i;
    for (int j = (LOG)-1; j >= (0); --j) {
      if (((n - 1) >> j) & 1) {
        ST[0][i] = par[j][ST[0][i]];
      }
    }
  }
  for (int j = (1); j < (LOG); ++j) {
    for (int i = (0); i < (m + 1 - (1 << j)); ++i) {
      ST[j][i] = min(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]);
    }
  }
  lg[1] = 0;
  for (int i = (2); i < (MAX); ++i) {
    lg[i] = lg[i - 1];
    if ((1 << (lg[i] + 1)) <= i) {
      lg[i]++;
    }
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    int curLg = lg[r - l + 1];
    printf("%d", min(ST[curLg][l], ST[curLg][r - (1 << curLg) + 1]) <= r);
  }
  return 0;
}
