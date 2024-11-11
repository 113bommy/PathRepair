#include <bits/stdc++.h>
using namespace std;
template <typename T>
T Abs(T first) {
  return (first < 0 ? -first : first);
}
template <typename T>
T Sqr(T first) {
  return (first * first);
}
string plural(string s) {
  return (int((s).size()) && s[int((s).size()) - 1] == 'x' ? s + "en"
                                                           : s + "s");
}
const int INF = (int)1e9;
const long double EPS = 1e-12;
const long double PI = acos(-1.0);
bool Read(int& first) {
  char c, r = 0, n = 0;
  first = 0;
  for (;;) {
    c = getchar();
    if ((c < 0) && (!r)) return (0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      first = first * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n) first = -first;
  return (1);
}
bool ReadLL(long long& first) {
  char c, r = 0, n = 0;
  first = 0;
  for (;;) {
    c = getchar();
    if ((c < 0) && (!r)) return (0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      first = first * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n) first = -first;
  return (1);
}
int N, M, K;
vector<int> con[300005], ch[300005];
bool vis[300005];
int dep[300005], par[300005];
bool W[300005];
vector<int> strt[300005], End[300005];
void rec(int i, int p) {
  vis[i] = 1;
  par[i] = p;
  if (p >= 0) dep[i] = dep[p] + 1;
  for (auto c : con[i])
    if (!vis[c]) {
      ch[i].push_back(c);
      rec(c, i);
    }
}
int ans;
int rec2(int i, int e) {
  for (auto c : ch[i]) {
    if (W[c]) {
      int e2 = rec2(c, 0);
      if (e && e2)
        ans--, e = 0;
      else if (!e && !e2)
        ans++, e = 1;
      else
        e = e2;
    } else
      rec2(c, 0);
  }
  return (e);
}
int main() {
  if (0) freopen("in.txt", "r", stdin);
  int i, j, k;
  Read(N), Read(M);
  while (M--) {
    Read(i), Read(j), i--, j--;
    con[i].push_back(j);
    con[j].push_back(i);
  }
  rec(0, -1);
  Read(K);
  for (i = 0; i < K; i++) {
    Read(j), Read(k), j--, k--;
    strt[i].push_back(j);
    End[i].push_back(k);
    while (j != k) {
      if (dep[j] > dep[k]) {
        W[j] = !W[j];
        j = par[j];
        if (j != k) strt[i].push_back(j);
      } else {
        W[k] = !W[k];
        k = par[k];
        if (j != k) End[i].push_back(k);
      }
    }
  }
  bool good = 1;
  for (i = 0; i < N - 1; i++)
    if (W[i]) good = 0;
  if (good) {
    printf("YES\n");
    for (i = 0; i < K; i++) {
      printf("%d\n", int((strt[i]).size()) + int((End[i]).size()));
      reverse((End[i]).begin(), (End[i]).end());
      for (auto v : strt[i]) printf("%d ", v + 1);
      for (auto v : End[i]) printf("%d ", v + 1);
      printf("\n");
    }
    return (0);
  }
  printf("NO\n");
  rec2(0, 0);
  printf("%d\n", ans);
  return (0);
}
