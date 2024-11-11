#include <bits/stdc++.h>
using namespace std;
const int N = 300001;
set<pair<long long int, long long int> >* T[N];
int A[N];
int S[N];
char s[N];
vector<int> adj[N];
long long int MOD1 = 1000000007LL;
long long int MOD2 = 1000000009LL;
void dfs(int st, int p = -1, long long int hash1 = 0LL,
         long long int hash2 = 0LL) {
  hash1 = (hash1 * 257LL + s[st] - 'a' + 1) % MOD1;
  hash2 = (hash2 * 43LL + s[st] - 'a' + 1) % MOD2;
  S[st] = 1;
  int mx = -1;
  for (auto c : adj[st]) {
    if (c != p) {
      dfs(c, st, hash1, hash2);
      S[st] += S[c];
      if (mx == -1 || S[mx] < S[c]) mx = c;
    }
  }
  set<pair<long long int, long long int> >* root;
  if (mx == -1)
    root = new set<pair<long long int, long long int> >;
  else {
    root = T[mx];
    for (auto c : adj[st]) {
      if (c != p && c != mx) root->insert(T[c]->begin(), T[c]->end());
    }
  }
  root->insert({hash1, hash2});
  T[st] = root;
  A[st] += T[st]->size();
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", A + i);
  }
  scanf("%s", s + 1);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  int mxc = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    if (mx == A[i])
      mxc++;
    else if (mx < A[i])
      mx = A[i], mxc = 0;
  }
  printf("%d\n%d\n", mx, mxc);
  return 0;
}
