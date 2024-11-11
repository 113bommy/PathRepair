#include <bits/stdc++.h>
using namespace std;
long long n[3];
vector<int> tree[3][100000];
long long S[3][100000], sts[3][100000], mxx[3], sum[3];
long long fsubtree(int x, int y, int t) {
  sts[t][x] = 1;
  for (int i = 0, _n = tree[t][x].size(); i < _n; i++)
    if (tree[t][x][i] != y) sts[t][x] += fsubtree(tree[t][x][i], x, t);
  return sts[t][x];
}
long long fsum(int x, int y, int t) {
  S[t][x] = 0LL;
  for (int i = 0, _n = tree[t][x].size(); i < _n; i++)
    if (tree[t][x][i] != y) S[t][x] += fsum(tree[t][x][i], x, t);
  return S[t][x] + sts[t][x];
}
void fsum2(int x, int y, int t, long long up, long long upcnt) {
  for (int i = 0, _n = tree[t][x].size(); i < _n; i++)
    if (tree[t][x][i] != y) {
      long long toadd =
          up + S[t][x] - S[t][tree[t][x][i]] - sts[t][tree[t][x][i]];
      toadd += sts[t][x] - sts[t][tree[t][x][i]] + upcnt;
      fsum2(tree[t][x][i], x, t, toadd,
            upcnt + sts[t][x] - sts[t][tree[t][x][i]]);
    }
  S[t][x] += up;
  mxx[t] = max(mxx[t], S[t][x]);
  sum[t] += S[t][x];
}
long long ANS = 0LL;
pair<long long, int> mfx[3][100000][2];
long long rmx[3][100000];
long long fbestsub(int x, int y, int t, long long k) {
  long long bscore = S[t][x] * n[(t + 2) % 3] + 2 * k;
  mfx[t][x][0] = mfx[t][x][1] = make_pair(bscore, x);
  for (int i = 0, _n = tree[t][x].size(); i < _n; i++)
    if (tree[t][x][i] != y) {
      pair<long long, int> tmp =
          make_pair(fbestsub(tree[t][x][i], x, t, k), tree[t][x][i]);
      if (tmp > mfx[t][x][0]) {
        swap(mfx[t][x][0], mfx[t][x][1]);
        mfx[t][x][0] = tmp;
      } else if (tmp > mfx[t][x][1])
        mfx[t][x][1] = tmp;
    }
  return mfx[t][x][0].first + k;
}
void pushbestsub(int x, int y, int t, long long bst, long long k) {
  for (int i = 0, _n = tree[t][x].size(); i < _n; i++)
    if (tree[t][x][i] != y) {
      if (mfx[t][x][0].second != tree[t][x][i])
        pushbestsub(tree[t][x][i], x, t, max(bst, mfx[t][x][0].first) + k, k);
      else
        pushbestsub(tree[t][x][i], x, t, max(bst, mfx[t][x][1].first) + k, k);
    }
  rmx[t][x] = max(bst, mfx[t][x][0].first);
}
void calcAns(int x, int y, int t) {
  for (int i = 0, _n = tree[t][x].size(); i < _n; i++)
    if (tree[t][x][i] != y) calcAns(tree[t][x][i], x, t);
  long long val = n[t] * mxx[(t + 1) % 3] + n[t] * n[(t + 1) % 3] +
                  n[(t + 1) % 3] * S[t][x];
  val += n[t] * mxx[(t + 2) % 3] + n[t] * n[(t + 2) % 3];
  val += n[(t + 1) % 3] * mxx[(t + 2) % 3];
  val += n[(t + 2) % 3] * mxx[(t + 1) % 3];
  val += rmx[t][x];
  ANS = max(ANS, val);
}
int main() {
  for (int i = 0, _n = 3; i < _n; i++) cin >> n[i];
  for (int i = 0, _n = 3; i < _n; i++)
    for (int j = 0, _n = n[i] - 1; j < _n; j++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      tree[i][u].push_back(v);
      tree[i][v].push_back(u);
    }
  for (int i = 0, _n = 3; i < _n; i++) {
    fsubtree(0, -1, i);
    fsum(0, -1, i);
    fsum2(0, -1, i, 0, 0);
  }
  for (int i = 0, _n = 3; i < _n; i++) {
    long long kk = n[(i + 1) % 3] * n[(i + 2) % 3];
    fbestsub(0, -1, i, kk);
    pushbestsub(0, -1, i, -1000000000000LL, kk);
    calcAns(0, -1, i);
  }
  cout << ANS + (sum[0] + sum[1] + sum[2]) / 2 << "\n";
  return 0;
}
