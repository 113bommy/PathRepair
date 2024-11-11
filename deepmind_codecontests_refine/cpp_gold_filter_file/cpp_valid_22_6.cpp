#include <bits/stdc++.h>
using namespace std;
const int N = 42, K = 11;
int n, k, cnt, mark[N], nw[K];
vector<long long> v[K], mask[K];
void do_it(long long u, int x) {
  for (int i = 0; i < nw[x] + 1; i++) {
    int cnt = i + __builtin_popcountll(u & mask[x].back());
    v[x + 1].push_back((u & (1ll << n) - 1 - mask[x].back()) | mask[x][cnt]);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int x, u;
    long long msk = 0;
    mask[i].push_back(0);
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> u;
      u--;
      msk |= (1ll << u);
      mask[i].push_back(msk);
      if (!mark[u]) {
        cnt++;
        nw[i]++;
        mark[u] = 1;
      }
    }
  }
  v[0].push_back(0);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      do_it(v[i][j], i);
    }
  }
  if (n != cnt && n > 1) return cout << "REJECTED" << endl, 0;
  for (int i = 0; i < v[k].size(); i++) {
    int cnt = __builtin_popcountll(v[k][i]);
    if ((1ll << cnt) - 1 != v[k][i]) return cout << "REJECTED" << endl, 0;
  }
  cout << "ACCEPTED" << endl;
}
