#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
inline string IntToString(long long a) {
  char x[100];
  sprintf(x, "%lld", a);
  string s = x;
  return s;
}
inline long long StringToInt(string a) {
  char x[100];
  long long res;
  strcpy(x, a.c_str());
  sscanf(x, "%lld", &res);
  return res;
}
inline string GetString(void) {
  char x[1000005];
  scanf("%s", x);
  string s = x;
  return s;
}
inline string uppercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
inline string lowercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
inline void OPEN(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
class SuffixArray {
 public:
  int process[21][200005];
  int n, m, ada[200005];
  pair<pair<int, int>, int> data[200005], data2[200005];
  int A[200005];
  void counting(void) {
    memset(ada, 0, sizeof(ada));
    int maks = 0;
    for (int(i) = (0); (i) < (n); ++(i)) {
      ++ada[data[i].first.first + 1];
      maks = max(maks, data[i].first.first);
    }
    for (int(i) = (0); (i) <= (maks); ++(i)) ada[i + 1] += ada[i];
    for (int(i) = (n - 1); (i) >= (0); --(i)) {
      data2[ada[data[i].first.first + 1] - 1] = data[i];
      --ada[data[i].first.first + 1];
    }
    for (int(i) = (0); (i) < (n); ++(i)) data[i] = data2[i];
  }
  void build(string s) {
    n = (int)s.size();
    for (int(i) = (0); (i) < (n); ++(i)) process[0][i] = s[i] - 'a';
    m = 0;
    for (int i = 0; (1 << i) <= n; ++i, ++m)
      ;
    for (int(i) = (1); (i) <= (m); ++(i)) {
      memset(ada, 0, sizeof(ada));
      for (int(j) = (0); (j) < (n); ++(j)) {
        int k = j + (1 << (i - 1));
        data[j] = make_pair(
            make_pair(k < n ? process[i - 1][k] : -1, process[i - 1][j]), j);
      }
      counting();
      for (int(j) = (0); (j) < (n); ++(j))
        swap(data[j].first.first, data[j].first.second);
      counting();
      int x = -1;
      for (int(j) = (0); (j) < (n); ++(j)) {
        if (j == 0 || data[j].first != data[j - 1].first) ++x;
        process[i][data[j].second] = x;
      }
    }
    for (int(i) = (0); (i) < (n); ++(i)) A[process[m][i]] = i;
  }
  int LCP(int a, int b) {
    int ret = 0;
    for (int(i) = (m); (i) >= (0); --(i)) {
      if (process[i][a] == process[i][b]) {
        ret += min(n, (1 << i));
        a += min(n, (1 << i));
        b += min(n, (1 << i));
      }
      if (b >= n) break;
    }
    return ret;
  }
};
string s, t;
string ss;
int n, m, k;
SuffixArray SA;
vector<int> isi;
int dp[1005][1005][15];
int jahja(int x, int y, int rem) {
  if (x >= m || y >= n || rem == 0) return 0;
  int &ret = dp[x][y][rem];
  if (ret >= 0) return ret;
  ret = max(jahja(x + 1, y, rem), jahja(x, y + 1, rem));
  int lcp = min(SA.LCP(x, y + m), m - x);
  ret = max(ret, lcp + jahja(x + lcp, y + lcp, rem - 1));
  return ret;
}
int main() {
  scanf("%d %d %d", &m, &n, &k);
  s = GetString();
  t = GetString();
  ss = s + t;
  SA.build(ss);
  memset(dp, -1, sizeof(dp));
  int risan = jahja(0, 0, k);
  printf("%d\n", risan);
  return 0;
}
