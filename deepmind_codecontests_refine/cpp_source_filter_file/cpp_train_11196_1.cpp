#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
template <typename T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
const int MAXS = 204;
const int MAXC = 26;
set<int> out[MAXS];
long long ov[MAXS];
long long f[MAXS];
long long g[MAXS][MAXC];
int buildMatchingMachine(string arr[], int k) {
  for (long long i = 0; i < MAXS; i++)
    for (long long j = 0; j < MAXC; j++) g[i][j] = -1;
  int states = 1;
  for (int i = 0; i < k; ++i) {
    const string &word = arr[i];
    int currentState = 0;
    for (int j = 0; j < word.size(); ++j) {
      int ch = word[j] - 'a';
      if (g[currentState][ch] == -1) g[currentState][ch] = states++;
      currentState = g[currentState][ch];
    }
    out[currentState].insert(i);
  }
  for (int ch = 0; ch < MAXC; ++ch)
    if (g[0][ch] == -1) g[0][ch] = 0;
  for (long long i = 0; i < MAXS; i++) f[i] = -1;
  queue<int> q;
  for (int ch = 0; ch < MAXC; ++ch) {
    if (g[0][ch] != 0) {
      f[g[0][ch]] = 0;
      q.push(g[0][ch]);
    }
  }
  while (q.size()) {
    int state = q.front();
    q.pop();
    for (int ch = 0; ch < MAXC; ++ch) {
      if (g[state][ch] != -1) {
        int failure = f[state];
        while (g[failure][ch] == -1) failure = f[failure];
        failure = g[failure][ch];
        f[g[state][ch]] = failure;
        for (auto &w : out[failure]) out[g[state][ch]].insert(w);
        q.push(g[state][ch]);
      }
    }
  }
  return states;
}
int findNextState(int currentState, char nextInput) {
  int answer = currentState;
  int ch = nextInput - 'a';
  while (g[answer][ch] == -1) answer = f[answer];
  return g[answer][ch];
}
const long long INF = 1e17;
vector<vector<long long> > matrixMul(const vector<vector<long long> > &a,
                                     const vector<vector<long long> > &b) {
  int n = a.size();
  int m = a[0].size();
  int k = b[0].size();
  vector<vector<long long> > res(n, vector<long long>(k));
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < k; j++) res[i][j] = -INF;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++)
      for (int p = 0; p < m; p++) chkmax(res[i][j], a[i][p] + b[p][j]);
  return res;
}
vector<vector<long long> > matrixPow(const vector<vector<long long> > &a,
                                     int p) {
  assert(p > 0);
  if (p == 1) return a;
  if (p & 1) return matrixMul(a, matrixPow(a, p - 1));
  return matrixPow(matrixMul(a, a), p / 2);
}
string ss[204];
long long sv[204];
int main() {
  ios_base::sync_with_stdio(false);
  long long n, l;
  cin >> n >> l;
  for (long long i = 0; i < n; i++) cin >> sv[i];
  for (long long i = 0; i < n; i++) cin >> ss[i];
  long long sn = buildMatchingMachine(ss, n);
  for (long long i = 0; i < sn; i++) {
    ov[i] = 0;
    for (auto &w : out[i]) ov[i] += sv[w];
  }
  vector<vector<long long> > mat(sn, vector<long long>(sn));
  for (long long i = 0; i < sn; i++)
    for (long long j = 0; j < sn; j++) mat[i][j] = -INF;
  for (long long i = 0; i < sn; i++) {
    for (long long c = 0; c < 26; c++) {
      char ch = c + 'a';
      long long j = findNextState(i, ch);
      chkmax(mat[i][j], ov[j]);
    }
  }
  long long ans = 0;
  vector<vector<long long> > res = matrixPow(mat, l);
  for (long long j = 0; j < sn; j++) {
    chkmax(ans, res[0][j]);
  }
  cout << ans << endl;
}
