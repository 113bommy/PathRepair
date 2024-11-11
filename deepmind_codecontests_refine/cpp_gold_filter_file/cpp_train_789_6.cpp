#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 100000 + 5;
int A[maxn];
vector<int> D[maxn];
int visit[maxn];
map<pair<int, int>, int> E;
int dfs(int a) {
  for (int i = 0; i < D[a].size(); i++) {
    if (visit[D[a][i]] == 0) {
      visit[D[a][i]] = 1;
      dfs(D[a][i]);
      if (A[D[a][i]] == 1) {
        E[make_pair(a, D[a][i])] = 1;
        E[make_pair(D[a][i], a)] = 1;
        A[a] = 1 - A[a];
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  long long sum = 0;
  memset(A, 0, sizeof(A));
  vector<int> K;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    if (A[i] != -1)
      sum += A[i];
    else
      K.push_back(i);
  }
  if (K.size() == 0 && sum % 2 == 1)
    cout << -1 << endl;
  else {
    if (sum % 2 == 1) {
      A[K[0]] = 1;
      for (int t = 1; t < K.size(); t++) {
        A[K[t]] = 0;
      }
    } else {
      for (int t = 0; t < K.size(); t++) {
        A[K[t]] = 0;
      }
    }
    int from, to;
    vector<pair<int, int> > F;
    for (int d = 0; d < n - 1; d++) {
      scanf("%d%d", &from, &to);
      D[from].push_back(to);
      D[to].push_back(from);
      F.push_back(make_pair(from, to));
    }
    memset(visit, 0, sizeof(visit));
    visit[1] = 1;
    dfs(1);
    vector<int> S;
    for (int i = 0; i < F.size(); i++) {
      if (E[F[i]] == 1) S.push_back(i + 1);
    }
    cout << S.size() << endl;
    for (int t = 0; t < S.size(); t++) {
      cout << S[t] << endl;
    }
  }
  return 0;
}
