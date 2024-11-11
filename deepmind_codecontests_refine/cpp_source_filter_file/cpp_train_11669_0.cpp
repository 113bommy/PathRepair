#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int INF = (1LL << 31) - 1;
const int sqrtN = 512;
struct SqrtDecomposition {
  int N, K;
  vector<int> data;
  vector<bool> lazyFlag;
  vector<int> lazyUpdate;
  SqrtDecomposition(int n) : N(n) {
    K = (N + sqrtN - 1) / sqrtN;
    data.assign(K * sqrtN, INF);
    lazyFlag.assign(K, false);
    lazyUpdate.assign(K, 0);
  }
  void eval(int k) {
    if (lazyFlag[k]) {
      lazyFlag[k] = false;
      for (int i = k * sqrtN; i < (k + 1) * sqrtN; ++i) {
        data[i] = lazyUpdate[k];
      }
    }
  }
  // [s, t)
  void update(int s, int t, int x) {
       int p = max(0, s / sqrtN - 1);
        int q = min(K, t / sqrtN + 1);
    for (int k = p; k < q; ++k) {
      int l = k * sqrtN, r = (k + 1) * sqrtN;
      if (r <= s || t <= l)
        continue;
      if (s <= l && r <= t) {
        lazyFlag[k] = true;
        lazyUpdate[k] = x;
      } else {
        eval(k);
        for (int i = max(s, l); i < min(t, r); ++i) {
          data[i] = x;
        }
      }
    }
  }
  int find(int i) {
    int k = i / sqrtN;
    eval(k);
    return data[i];
  }
};
 
signed main() {
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  SqrtDecomposition decomp(N);
  while (Q--) {
    int c;
    cin >> c;
    if (c == 0) {
      int s, t, x;
      cin >> s >> t >> x;
      decomp.update(s, t + 1, x);
    } else {
      int i;
      cin >> i;
      cout << decomp.find(i) << endl;
    }
  }
}