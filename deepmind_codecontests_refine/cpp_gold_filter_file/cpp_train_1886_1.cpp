#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;
vector<int> pi_fn(const string &s) {
  int n = ((int)(s).size());
  vector<int> p(n, 0);
  for (int i = 1, j = 0; i < n;) {
    if (s[i] == s[j])
      p[i++] = ++j;
    else if (j > 0)
      j = p[j - 1];
    else
      i++;
  }
  return p;
}
vector<int> KMP(const string &pat, const vector<int> &p, const string &text) {
  vector<int> res;
  for (int i = 0, j = 0; i < ((int)(text).size());) {
    if (text[i] == pat[j]) {
      i++;
      if (++j == ((int)(pat).size()))
        res.push_back(i - ((int)(pat).size())), j = p[j - 1];
    } else if (j > 0)
      j = p[j - 1];
    else
      i++;
  }
  return res;
}
int N, L[maxn] = {}, R[maxn];
string A[maxn], B[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (auto i = (0); i != (N); ++i) cin >> A[i];
  for (auto i = (0); i != (N); ++i) cin >> B[i];
  for (auto i = (0); i != (N); ++i) {
    R[i] = ((int)(A[i]).size());
    while (L[i] < R[i] && A[i][L[i]] == B[i][L[i]]) L[i]++;
    if (L[i] == R[i]) continue;
    R[i]--;
    while (A[i][R[i]] == B[i][R[i]]) R[i]--;
  }
  while (true) {
    char cha = '\0', chb = '\0';
    for (auto i = (0); i != (N); ++i) {
      if (L[i] == ((int)(A[i]).size())) continue;
      if (L[i] == 0 ||
          (cha && (cha != A[i][L[i] - 1] || chb != B[i][L[i] - 1])))
        goto donel;
      cha = A[i][L[i] - 1];
      chb = B[i][L[i] - 1];
    }
    for (auto i = (0); i != (N); ++i)
      if (L[i] != ((int)(A[i]).size())) L[i]--;
  }
donel:
  while (true) {
    char cha = '\0', chb = '\0';
    for (auto i = (0); i != (N); ++i) {
      if (L[i] == ((int)(A[i]).size())) continue;
      if (R[i] == ((int)(A[i]).size()) - 1 ||
          (cha && (cha != A[i][R[i] + 1] || chb != B[i][R[i] + 1])))
        goto doner;
      cha = A[i][R[i] + 1];
      chb = B[i][R[i] + 1];
    }
    for (auto i = (0); i != (N); ++i)
      if (L[i] != ((int)(A[i]).size())) R[i]++;
  }
doner:
  int len = -1;
  string S, T;
  for (auto i = (0); i != (N); ++i) {
    if (L[i] == ((int)(A[i]).size())) continue;
    if (len < 0) {
      len = R[i] - L[i] + 1;
      S = A[i].substr(L[i], len);
      T = B[i].substr(L[i], len);
      continue;
    }
    for (auto j = (0); j != (len); ++j)
      if (A[i][L[i] + j] != S[j] || B[i][L[i] + j] != T[j]) {
        cout << "NO\n";
        return 0;
      }
  }
  vector<int> p = pi_fn(S);
  for (auto i = (0); i != (N); ++i) {
    vector<int> ret = KMP(S, p, A[i]);
    if (ret.empty()) continue;
    for (auto j = (0); j != (len); ++j) A[i][ret.front() + j] = T[j];
  }
  for (auto i = (0); i != (N); ++i)
    for (auto j = (0); j != (((int)(A[i]).size())); ++j)
      if (A[i][j] != B[i][j]) {
        cout << "NO\n";
        return 0;
      }
  cout << "YES\n" << S << endl << T << endl;
  return 0;
}
