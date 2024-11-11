#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
const int N = 2e5 + 10;
int seg[2][1 << 5][2 * N];
int v[2 * N][5];
int n;
void build(int k) {
  for (int mask = 0; mask < 1 << k; mask++) {
    for (int cor = 0; cor < 2; cor++) {
      int *s = seg[cor][mask];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
          if ((1 << j) & mask)
            s[i + n] += v[i][j];
          else
            s[i + n] -= v[i][j];
        }
      }
      if (cor)
        for (int i = n - 1; i >= 1; i--)
          for (int id = 0; id < k; id++) s[i] = max(s[i << 1], s[i << 1 | 1]);
      else
        for (int i = n - 1; i >= 1; i--)
          for (int id = 0; id < k; id++) s[i] = min(s[i << 1], s[i << 1 | 1]);
    }
  }
}
int qry(int lo, int ro, int k) {
  int ans = 0, l, r;
  for (int mask = 0; mask < 1 << k; mask++) {
    int *s = seg[1][mask];
    int ans_max = -INT_MAX;
    l = lo, r = ro;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans_max = max(s[l++], ans_max);
      if (r & 1) ans_max = max(s[--r], ans_max);
    }
    int ans_min = INT_MAX;
    s = seg[0][mask];
    l = lo, r = ro;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans_min = min(s[l++], ans_min);
      if (r & 1) ans_min = min(s[--r], ans_min);
    }
    ans = max(ans, ans_max - ans_min);
  }
  return ans;
}
void up(int id, int k, vector<int> val) {
  for (int i = 0; i < k; i++) v[id][i] = val[i];
  for (int mask = 0; mask < 1 << k; mask++) {
    for (int cor = 0; cor < 2; cor++) {
      int *s = seg[cor][mask];
      s[id + n] = 0;
      for (int i = 0; i < k; i++) {
        if ((1 << i) & mask)
          s[id + n] += v[id][i];
        else
          s[id + n] -= v[id][i];
      }
      int pos = id;
      for (pos += n; pos > 1; pos >>= 1) {
        if (cor)
          s[pos >> 1] = max(s[pos], s[pos ^ 1]);
        else
          s[pos >> 1] = min(s[pos], s[pos ^ 1]);
      }
    }
  }
}
int k;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) scanf("%d", v[i] + j);
  }
  build(k);
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    char t;
    scanf(" %c", &t);
    if (t == '1') {
      int id;
      scanf("%d", &id);
      vector<int> vv;
      for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        vv.push_back(x);
      }
      up(id - 1, k, vv);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      printf("%d\n", qry(l, r, k));
    }
  }
  return 0;
}
