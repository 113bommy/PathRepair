#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
using namespace std;
set<long long int> s1, s2;
long long int vis[1000002];
vector<long long int> pr;
long long int spf[1000001];
void sieve() {
  spf[1] = 1;
  for (long long int i = 2; i < 1000001; i++) spf[i] = i;
  for (long long int i = 4; i < 1000001; i += 2) spf[i] = 2;
  for (long long int i = 3; i * i < 1000001; i++) {
    if (spf[i] == i) {
      for (long long int j = i * i; j < 1000001; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
vector<long long int> getF(long long int x) {
  vector<long long int> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
void seive() {
  long long int i, j;
  for (i = 2; i < 1000002; i++) {
    if (vis[i] == 0) {
      for (j = 2 * i; j < 1000002; j += i) vis[j] = 1;
      pr.push_back(i);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long int n;
  cin >> n;
  long long int i;
  sieve();
  seive();
  set<long long int> s;
  sort(pr.begin(), pr.end());
  long long int io = 0;
  for (i = 1; i <= n; i++) {
    long long int x;
    cin >> x;
    vector<long long int> pp = getF(x);
    long long int j;
    long long int flg = 0;
    for (j = 0; j < pp.size(); j++) {
      if (s.find(pp[j]) != s.end()) flg = 1;
    }
    if (flg == 0) {
      cout << x << " ";
      for (j = 0; j < pp.size(); j++) {
        s.insert(pp[j]);
      }
    }
    if (flg == 1) {
      vector<long long int> pp1;
      for (j = x + 1;; j++) {
        int flag = 0;
        pp1 = getF(j);
        for (long long int u = 0; u < pp1.size(); u++) {
          if (s.find(pp1[u]) != s.end()) flag = 1;
        }
        if (flag == 0) break;
      }
      cout << j << " ";
      for (long long int u = 0; u < pp1.size(); u++) s.insert(pp1[u]);
      long long int gg = n - i;
      for (long long int j = 0; j < pr.size(); j++) {
        if (s.find(pr[j]) == s.end()) {
          if (gg == 0) break;
          cout << pr[j] << " ";
          gg--;
        }
      }
      return 0;
    }
  }
}
