#include <bits/stdc++.h>
using namespace std;
long long int n, m, k;
long long int c[202020];
long long int cA;
long long int cB;
bool A[202020];
bool B[202020];
vector<long long int> X[2][2];
long long int pos[2][2];
long long int cost = 0;
long long int chosen = 0;
long long int S;
bool choose() {
  long long int besti = -1;
  long long int bestj = -1;
  long long int best = LLONG_MAX;
  auto tr = [&](long long int i, long long int j) {
    if (pos[i][j] == (long long int)X[i][j].size()) return;
    long long int val = X[i][j][pos[i][j]];
    if (val < best) {
      best = val;
      besti = i;
      bestj = j;
    }
  };
  bool needA = pos[1][0] + S < k;
  bool needB = pos[0][1] + S < k;
  if (needA && needB) {
    if (pos[0][0] == 0 || pos[1][0] == (long long int)X[1][0].size() ||
        pos[0][1] == (long long int)X[0][1].size())
      return false;
    cost -= X[0][0][--pos[0][0]];
    cost += X[1][0][pos[1][0]++];
    cost += X[0][1][pos[0][1]++];
    ++chosen;
    return true;
  }
  if (needA) {
    tr(1, 0);
  } else if (needB) {
    tr(0, 1);
  } else {
    tr(0, 1);
    tr(1, 0);
    tr(0, 0);
  }
  if (besti == -1) return false;
  ++chosen;
  cost += X[besti][bestj][pos[besti][bestj]++];
  return true;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (long long int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  cin >> cA;
  for (long long int i = 0; i < cA; ++i) {
    long long int x;
    cin >> x;
    --x;
    A[x] = true;
  }
  cin >> cB;
  for (long long int i = 0; i < cB; ++i) {
    long long int x;
    cin >> x;
    --x;
    B[x] = true;
  }
  for (long long int i = 0; i < n; ++i) {
    X[A[i]][B[i]].push_back(c[i]);
  }
  sort(X[0][0].begin(), X[0][0].end());
  sort(X[0][1].begin(), X[0][1].end());
  sort(X[1][0].begin(), X[1][0].end());
  sort(X[1][1].begin(), X[1][1].end());
  S = min((long long int)X[1][1].size(), m);
  for (long long int i = 0; i < S; ++i) {
    cost += X[1][1][i];
    ++chosen;
  }
  while (pos[1][0] + S < k) {
    if (pos[1][0] == (long long int)X[1][0].size()) {
      cout << "-1\n";
      return 0;
    }
    cost += X[1][0][pos[1][0]++];
    ++chosen;
  }
  while (pos[0][1] + S < k) {
    if (pos[0][1] == (long long int)X[0][1].size()) {
      cout << "-1\n";
      return 0;
    }
    cost += X[0][1][pos[0][1]++];
    ++chosen;
  }
  if (chosen > m) {
    cout << "-1\n";
    return 0;
  }
  while (chosen < m) {
    if (!choose()) {
      cout << "-1\n";
      return 0;
    }
  }
  long long int ret = cost;
  while (S > 0) {
    cost -= X[1][1][S - 1];
    --S;
    if (!choose()) {
      break;
    }
    ret = max(ret, cost);
  }
  cout << ret << "\n";
  return 0;
}
