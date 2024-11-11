#include <bits/stdc++.h>
using namespace std;
const int K = 12;
const int N = (int)1e5 + 37;
int n;
int k;
int q;
int tab[K + 1][N];
bitset<1 << K> b[N];
bitset<K * N> init[K + 1];
int go[N * K];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> q;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> tab[i][j];
    }
  }
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= k; i++) {
      int ones = 0;
      for (int it = 1; it <= k; it++) {
        ones += (tab[i][j] >= tab[it][j]);
      }
      for (int step = 1; step <= k; step++) {
        init[i][(j - 1) * k + step - 1] = (step <= ones);
      }
    }
  }
  for (int j = 0; j < n * k; j++) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
      if (init[i + 1][j]) {
        sum += (1 << i);
      }
    }
    go[j] = sum;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < n * k; j++) {
      b[i][go[j]] = init[i][j];
    }
  }
  int l = k;
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      l++;
      b[l] = b[x] | b[y];
    }
    if (t == 2) {
      l++;
      b[l] = b[x] & b[y];
    }
    if (t == 3) {
      int ones = 0;
      int l = (y - 1) * k;
      int r = y * k - 1;
      for (int j = l; j <= r; j++) {
        ones += b[x][go[j]];
      }
      vector<int> mipan;
      for (int i = 1; i <= k; i++) {
        mipan.push_back(tab[i][y]);
      }
      sort(mipan.begin(), mipan.end());
      cout << mipan[ones - 1] << "\n";
    }
  }
}
