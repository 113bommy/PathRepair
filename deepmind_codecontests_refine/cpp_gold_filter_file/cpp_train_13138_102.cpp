#include <bits/stdc++.h>
using namespace std;
inline bool leq(int a1, int a2, int b1, int b2) {
  return (a1 < b1 || a1 == b1 && a2 <= b2);
}
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
  return (a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
}
static void radixPass(int* a, int* b, int* r, int n, int K) {
  int* c = new int[K + 1];
  for (int i = 0; i <= K; i++) c[i] = 0;
  for (int i = 0; i < n; i++) c[r[a[i]]]++;
  for (int i = 0, sum = 0; i <= K; i++) {
    int t = c[i];
    c[i] = sum;
    sum += t;
  }
  for (int i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i];
  delete[] c;
}
void suffixArray(int* s, int* SA, int n, int K) {
  int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
  int* s12 = new int[n02 + 3];
  s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
  int* SA12 = new int[n02 + 3];
  SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
  int* s0 = new int[n0];
  int* SA0 = new int[n0];
  for (int i = 0, j = 0; i < n + (n0 - n1); i++)
    if (i % 3 != 0) s12[j++] = i;
  radixPass(s12, SA12, s + 2, n02, K);
  radixPass(SA12, s12, s + 1, n02, K);
  radixPass(s12, SA12, s, n02, K);
  int name = 0, c0 = -1, c1 = -1, c2 = -1;
  for (int i = 0; i < n02; i++) {
    if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
      name++;
      c0 = s[SA12[i]];
      c1 = s[SA12[i] + 1];
      c2 = s[SA12[i] + 2];
    }
    if (SA12[i] % 3 == 1) {
      s12[SA12[i] / 3] = name;
    } else {
      s12[SA12[i] / 3 + n0] = name;
    }
  }
  if (name < n02) {
    suffixArray(s12, SA12, n02, name);
    for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
  } else
    for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
  for (int i = 0, j = 0; i < n02; i++)
    if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
  radixPass(s0, SA0, s, n0, K);
  for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
    int i = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    int j = SA0[p];
    if (SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3])
                     : leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j],
                           s[j + 1], s12[j / 3 + n0])) {
      SA[k] = i;
      t++;
      if (t == n02)
        for (k++; p < n0; p++, k++) SA[k] = SA0[p];
    } else {
      SA[k] = j;
      p++;
      if (p == n0)
        for (k++; t < n02; t++, k++)
          SA[k] = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    }
  }
  delete[] s12;
  delete[] SA12;
  delete[] SA0;
  delete[] s0;
}
vector<int> kasai(const string& s, const vector<int>& sa) {
  int n = s.size(), k = 0;
  vector<int> lcp(n, 0);
  vector<int> rank(n, 0);
  for (int i = 0; i < n; i++) rank[sa[i]] = i;
  for (int i = 0; i < n; i++, k ? k-- : 0) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = sa[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    lcp[rank[i]] = k;
  }
  return lcp;
}
int Mini[1000 * 1000 + 5][20];
void precalcMin(vector<int>& lcp, int n) {
  int len = 1;
  int lg = 0;
  for (int i = 0; i <= n - 1; i++) {
    Mini[i][0] = lcp[i];
  }
  lg++;
  len *= 2;
  while (lg <= 19) {
    for (int i = 0; i <= n - len; i++) {
      Mini[i][lg] = min(Mini[i][lg - 1], Mini[i + len / 2][lg - 1]);
    }
    lg++;
    len *= 2;
  }
}
int getMin(int i, int j) {
  int n = j - i + 1;
  int lg = 0;
  while (n > 1) {
    lg++;
    n /= 2;
  }
  int ans = min(Mini[i][lg], Mini[j + 1 - (1 << lg)][lg]);
  return ans;
}
int sufind[1000 * 1000 + 5];
bool feasible(string& s, vector<int>& lcp, int len) {
  int lastind = s.size() - len;
  int lastSufInd = sufind[lastind];
  if (lastSufInd > sufind[0])
    return false;
  else {
    int moves = max(2, sufind[0] - lastSufInd);
    int minlcp = getMin(lastSufInd, lastSufInd + moves - 1);
    if (minlcp < len) return false;
    return true;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  getline(cin, s);
  int* s0 = new int[s.size() + 3];
  int* sa = new int[s.size() + 3];
  vector<int> sa_in(s.size() + 3, 0);
  for (int i = 0; i < s.size(); i++) {
    s0[i] = s[i];
  }
  s0[s.size()] = 0;
  s0[s.size() + 1] = 0;
  s0[s.size() + 2] = 0;
  suffixArray(s0, sa, s.size(), 257);
  for (int i = 0; i < s.size(); i++) {
    sufind[sa[i]] = i;
  }
  for (int i = 0; i < s.size(); i++) {
    sa_in[i] = sa[i];
  }
  vector<int> lcp = kasai(s, sa_in);
  precalcMin(lcp, s.size());
  int ans = 0;
  if (s.size() >= 3) {
    for (ans = s.size() - 2; ans > 0; ans--) {
      if (feasible(s, lcp, ans)) break;
    }
  }
  if (ans == 0) {
    printf("Just a legend");
  } else {
    for (int i = 0; i < ans; i++) {
      printf("%c", s[i]);
    }
  }
  delete[] s0;
  delete[] sa;
  return 0;
}
