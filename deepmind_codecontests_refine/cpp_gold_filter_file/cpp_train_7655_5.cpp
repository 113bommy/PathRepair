#include <bits/stdc++.h>
using namespace std;
int INF = pow(10, 9);
vector<vector<int>> up;
vector<int> deep;
int k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  k = log2(n) + 1;
  deep.resize(n);
  up.resize(k);
  int maxi1 = 0;
  int maxi2 = 0;
  int d = 0;
  for (int i = 0; i < k; i++) {
    up[i].resize(n);
  }
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    up[0][i] = p;
    deep[i] = deep[p] + 1;
    for (int j = 1; j < k; j++) {
      up[j][i] = up[j - 1][up[j - 1][i]];
    }
    int a = maxi1, b = i;
    int ai = 0;
    if (deep[a] > deep[b]) swap(a, b);
    for (int j = k - 1; j >= 0; j--) {
      if (deep[up[j][b]] < deep[a]) continue;
      ai += deep[b] - deep[up[j][b]];
      b = up[j][b];
    }
    if (a != b) {
      for (int j = k - 1; j >= 0; j--) {
        if (up[j][a] != up[j][b]) {
          ai += 2 * (deep[b] - deep[up[j][b]]);
          a = up[j][a];
          b = up[j][b];
        }
      }
      ai += 2;
    }
    a = maxi2, b = i;
    int bi = 0;
    if (deep[a] > deep[b]) swap(a, b);
    for (int j = k - 1; j >= 0; j--) {
      if (deep[up[j][b]] < deep[a]) continue;
      bi += deep[b] - deep[up[j][b]];
      b = up[j][b];
    }
    if (a != b) {
      for (int j = k - 1; j >= 0; j--) {
        if (up[j][a] != up[j][b]) {
          bi += 2 * (deep[b] - deep[up[j][b]]);
          a = up[j][a];
          b = up[j][b];
        }
      }
      bi += 2;
    }
    if (bi > d && bi >= ai) {
      d = bi;
      maxi1 = i;
    } else if (ai > d && ai >= bi) {
      d = ai;
      maxi2 = i;
    }
    cout << d << ' ';
  }
  cout << '\n';
  return 0;
}
