#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;
int in() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
vector<int> pres[28];
int pref[300000];
int suf[300000];
int code(char c) { return c - 'a'; }
void solve() {
  int N, M;
  string s, t;
  cin >> s >> t;
  N = s.size();
  M = t.size();
  pref[0] = (s[0] == t[0]) ? 1 : 0;
  suf[N - 1] = (s[N - 1] == t[M - 1]) ? M - 2 : M - 1;
  int i;
  for (i = 0; i < 28; i++) pres[i].clear();
  for (i = 0; i < M; i++) pres[code(t[i])].push_back(i);
  if (M > N || pref[0] == 0 || suf[N - 1] == M - 1) {
    cout << "No" << endl;
    return;
  }
  for (i = 1; i < N; i++) {
    if (pref[i - 1] < M && s[i] == t[pref[i - 1]]) {
      pref[i] = pref[i - 1] + 1;
    } else {
      pref[i] = pref[i - 1];
    }
    if (suf[N - i] >= 0 && s[N - 1 - i] == t[suf[N - i]]) {
      suf[N - i - 1] = suf[N - i] - 1;
    } else {
      suf[N - i - 1] = suf[N - i];
    }
  }
  for (i = 1; i < N - 1; i++) {
    int l = pref[i - 1];
    int h = suf[i + 1];
    int c = code(s[i]);
    int pos = lower_bound(pres[c].begin(), pres[c].end(), h) - pres[c].begin();
    if (pos >= (int)pres[c].size() || pres[c][pos] < h || pres[c][pos] > l) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}
int main() {
  solve();
  return 0;
}
