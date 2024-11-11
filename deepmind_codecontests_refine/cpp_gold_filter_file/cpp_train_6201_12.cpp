#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
int n, m;
long long an[SIZE];
pair<int, int> q[SIZE];
vector<int> RU[SIZE], RD[SIZE];
void mii(long long& x, long long v) {
  if (x == -1 || x > v) x = v;
}
map<pair<int, int>, int> H;
vector<int> e[SIZE];
pair<int, int> pp[SIZE];
int id;
int ADD(pair<int, int> x) {
  if (H.count(x)) return H[x];
  pp[id] = x;
  return H[x] = id++;
}
void go(int x, int lt, long long t) {
  int y = e[x][0];
  if (lt == y) {
    if (((int)(e[x]).size()) == 1) return;
    y = e[x][1];
  }
  if (pp[x].first + pp[x].second == pp[y].first + pp[y].second) {
    int v = pp[x].first + pp[x].second;
    for (int i = 0; i < (((int)(RD[v]).size())); ++i) {
      int you = RD[v][i];
      mii(an[you], t + abs(pp[x].first - q[you].first));
    }
  } else {
    int v = pp[x].first - pp[x].second + m;
    for (int i = 0; i < (((int)(RU[v]).size())); ++i) {
      int you = RU[v][i];
      mii(an[you], t + abs(pp[x].first - q[you].first));
    }
  }
  go(y, x, t + abs(pp[x].first - pp[y].first));
}
int main() {
  memset((an), -1, sizeof((an)));
  int K;
  scanf("%d%d%d", &(n), &(m), &(K));
  for (int i = 0; i < (n); ++i) {
    int x = ADD(make_pair(i, 0));
    int y = -1;
    if (i <= n - m) {
      y = ADD(make_pair(i + m, m));
    } else {
      y = ADD(make_pair(n, n - i));
    }
    e[x].push_back(y);
    e[y].push_back(x);
    x = ADD(make_pair(i, m));
    if (i + m <= n) {
      y = ADD(make_pair(i + m, 0));
    } else {
      y = ADD(make_pair(n, i + m - n));
    }
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = (1); i < (m); ++i) {
    int x = ADD(make_pair(0, i));
    int y = -1;
    if (i + n <= m) {
      y = ADD(make_pair(n, i + n));
    } else {
      y = ADD(make_pair(m - i, m));
    }
    e[x].push_back(y);
    e[y].push_back(x);
    if (i >= n) {
      y = ADD(make_pair(n, i - n));
    } else {
      y = ADD(make_pair(i, 0));
    }
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 0; i < (K); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    q[i] = make_pair(x, y);
    RD[x + y].push_back(i);
    RU[x - y + m].push_back(i);
  }
  go(0, 0, 0);
  for (int i = 0; i < (K); ++i) printf("%I64d\n", an[i]);
  return 0;
}
