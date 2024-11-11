#include <bits/stdc++.h>
using namespace std;
struct sabuild {
  int i, val[2];
} temp[600010];
string t[100010];
queue<sabuild> Q[600010];
vector<int> S;
int ord[600010], sa[600010], lcp[600010], from[100010], len[100010];
int n, c[100010];
long long pre[600010];
void sortit(sabuild v[], int wh) {
  int maxv = 0;
  for (int i = 0; i < S.size(); ++i) {
    Q[v[i].val[wh]].push(v[i]);
    maxv = max(maxv, v[i].val[wh]);
  }
  int nr = 0;
  for (int i = 0; i <= maxv; ++i) {
    while (!Q[i].empty()) {
      v[nr++] = Q[i].front();
      Q[i].pop();
    }
  }
}
void radix_sort(sabuild v[]) {
  sortit(v, 1);
  sortit(v, 0);
}
void build_SA() {
  for (int i = 0; i < S.size(); ++i) {
    ord[i] = S[i];
  }
  for (int sz = 0; (1 << sz) <= S.size(); ++sz) {
    for (int i = 0; i < S.size(); ++i) {
      temp[i].val[0] = ord[i];
      temp[i].val[1] = (i + (1 << sz) < S.size() ? ord[i + (1 << sz)] : 0);
      temp[i].i = i;
    }
    radix_sort(temp);
    int nr = 1;
    for (int i = 0; i < S.size(); ++i) {
      if (i != 0 && (temp[i].val[0] != temp[i - 1].val[0] ||
                     temp[i].val[1] != temp[i - 1].val[1]))
        ++nr;
      ord[temp[i].i] = nr;
    }
  }
  for (int i = 0; i < S.size(); ++i) sa[ord[i]] = i;
}
void build_LCP() {
  int k = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (ord[i] == S.size()) {
      lcp[ord[i]] = 0;
      continue;
    }
    for (int j = sa[ord[i] + 1];
         i + k < S.size() && j + k < S.size() && S[i + k] == S[j + k]; ++k)
      ;
    lcp[ord[i]] = k;
    if (k) --k;
  }
}
void solve() {
  for (int i = 1; i <= S.size(); ++i) pre[i] = pre[i - 1] + c[from[sa[i]]];
  stack<int> sval, sind;
  sval.push(-1);
  sind.push(0);
  long long ans = 0;
  for (int i = 1; i <= S.size(); ++i) {
    while (len[sa[i]] == sval.top()) {
      sval.pop();
      sind.pop();
    }
    sval.push(len[sa[i]]);
    sind.push(i);
    while (lcp[i] <= sval.top()) {
      int val = sval.top();
      sval.pop();
      sind.pop();
      if (val != lcp[i]) ans = max(ans, 1LL * val * (pre[i] - pre[sind.top()]));
    }
    sval.push(lcp[i]);
    sind.push(i);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  for (int i = 1; i <= n; ++i) cin >> c[i];
  int chars = 26;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < t[i].length(); ++j) {
      from[S.size()] = i;
      len[S.size()] = t[i].length() - j;
      S.push_back(t[i][j] - 'a' + 1);
    }
    from[S.size()] = 0;
    len[S.size()] = 1;
    S.push_back(++chars);
  }
  build_SA();
  build_LCP();
  solve();
}
