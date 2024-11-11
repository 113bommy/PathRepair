#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int INF = (int)1E9 + 7;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int N = 3000;
const int S = 2000000;
char buf[S];
int n, m;
string bs[N];
int st[N];
vector<int> zbs[26][N];
int zb[26][N];
int sq[N];
string s;
int z[N][N];
int solve(int pre, int len) {
  if (len == 0) return -1;
  if (pre < 0 || pre + 1 < len) return -2;
  if (z[pre][len] == -1) {
    z[pre][len] = solve(pre - 1, len);
    int mpos = solve(pre - 1, len - 1);
    if (mpos == -2) return z[pre][len];
    mpos++;
    if (mpos >= st[m - 1] + int((bs[sq[m - 1]]).size())) return z[pre][len];
    int idx = (upper_bound(st, st + m, mpos) - st) - 1;
    int sv = -2;
    if (zbs[s[pre] - 'a'][sq[idx]][mpos - st[idx]] != -2) {
      sv = st[idx] + zbs[s[pre] - 'a'][sq[idx]][mpos - st[idx]];
    } else {
      if (idx != m - 1) sv = zb[s[pre] - 'a'][idx + 1];
    }
    if (sv != -2 && (z[pre][len] == -2 || z[pre][len] > sv)) z[pre][len] = sv;
  }
  return z[pre][len];
}
int main() {
  cin >> n;
  gets(buf);
  for (int i = 0; i < int(n); ++i) {
    gets(buf);
    bs[i] = buf;
    for (int j = 0; j < int(26); ++j) {
      zbs[j][i].resize(int((bs[i]).size()));
      zbs[j][i][int((bs[i]).size()) - 1] =
          (bs[i][int((bs[i]).size()) - 1] == j + 'a')
              ? (int((bs[i]).size()) - 1)
              : (-2);
      for (int k = int((bs[i]).size()) - 2; k >= 0; --k) {
        zbs[j][i][k] = zbs[j][i][k + 1];
        if (bs[i][k] == j + 'a') zbs[j][i][k] = k;
      }
    }
  }
  cin >> m;
  for (int i = 0; i < int(m); ++i) {
    cin >> sq[i];
    sq[i]--;
    if (i == 0)
      st[i] = 0;
    else
      st[i] = st[i - 1] + int((bs[sq[i - 1]]).size());
  }
  for (int j = 0; j < int(26); ++j) {
    zb[j][m - 1] = st[m - 1] + zbs[j][sq[m - 1]][0];
    if (zbs[j][sq[m - 1]][0] == -2) zb[j][m - 1] = -2;
    for (int i = m - 2; i >= 0; --i) {
      zb[j][i] = zb[j][i + 1];
      if (zbs[j][sq[i]][0] != -2) zb[j][i] = st[i] + zbs[j][sq[i]][0];
    }
  }
  gets(buf);
  gets(buf);
  s = buf;
  memset(z, -1, sizeof(z));
  for (int i = int(int((s).size())) - 1; i >= 0; --i)
    if (solve(int((s).size()) - 1, i + 1) != -2) {
      cout << i + 1 << endl;
      return 0;
    }
  cout << 0 << endl;
  return 0;
  return 0;
}
