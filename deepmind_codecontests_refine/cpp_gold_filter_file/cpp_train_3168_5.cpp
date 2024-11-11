#include <bits/stdc++.h>
using namespace std;
const int BUF = 300005;
const int MAX_SIZE = 4000000;
const int QUERY = 100005;
class SegTree {
 public:
  long long v[BUF * 4];
  long long lazy[BUF * 4];
  int pos[BUF];
  SegTree() {}
  void init(vector<int> &p) {
    memset(v, 0, sizeof(v));
    memset(lazy, 0, sizeof(lazy));
    for (int i = 0; i < p.size(); ++i) pos[i] = p[i];
  }
  long long get(int node, int L, int R, int LQ, int RQ) {
    if (R < LQ || RQ < L) return 0;
    if (lazy[node] != 0) {
      v[node] += lazy[node] * (pos[R + 1] - pos[L]);
      if (L != R) {
        lazy[node * 2 + 1] += lazy[node];
        lazy[node * 2 + 2] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (LQ <= L && R <= RQ) return v[node];
    long long s = get(node * 2 + 1, L, (L + R) / 2, LQ, RQ);
    long long t = get(node * 2 + 2, (L + R) / 2 + 1, R, LQ, RQ);
    return s + t;
  }
  long long update(int node, int L, int R, int LQ, int RQ, long long delta) {
    if (lazy[node] != 0) {
      v[node] += lazy[node] * (pos[R + 1] - pos[L]);
      if (L != R) {
        lazy[node * 2 + 1] += lazy[node];
        lazy[node * 2 + 2] += lazy[node];
      }
      lazy[node] = 0;
    }
    if (R < LQ || RQ < L) return v[node];
    if (LQ <= L && R <= RQ) {
      v[node] += delta * (pos[R + 1] - pos[L]);
      if (L != R) {
        lazy[node * 2 + 1] += delta;
        lazy[node * 2 + 2] += delta;
      }
      return v[node];
    }
    long long s = update(node * 2 + 1, L, (L + R) / 2, LQ, RQ, delta);
    long long t = update(node * 2 + 2, (L + R) / 2 + 1, R, LQ, RQ, delta);
    return v[node] = s + t;
  }
};
int row, col, nQuery;
int query[QUERY][6];
void read() {
  scanf("%d%d%d", &row, &col, &nQuery);
  for (int i = 0; i < nQuery; ++i) {
    scanf("%d", &query[i][0]);
    for (int j = 0; j < (query[i][0] == 0 ? 5 : 4); ++j)
      scanf("%d", &query[i][j + 1]);
  }
}
void work() {
  vector<int> rList, cList;
  map<int, int> r2idx, c2idx;
  rList.push_back(0);
  rList.push_back(MAX_SIZE + 1);
  cList.push_back(0);
  cList.push_back(MAX_SIZE + 1);
  for (int i = 0; i < nQuery; ++i) {
    rList.push_back(query[i][1]);
    rList.push_back(query[i][3]);
    rList.push_back(query[i][3] + 1);
    cList.push_back(query[i][2]);
    cList.push_back(query[i][4]);
    cList.push_back(query[i][4] + 1);
  }
  sort(rList.begin(), rList.end());
  rList.erase(unique(rList.begin(), rList.end()), rList.end());
  sort(cList.begin(), cList.end());
  cList.erase(unique(cList.begin(), cList.end()), cList.end());
  for (int i = 0; i < rList.size(); ++i) r2idx[rList[i]] = i;
  for (int i = 0; i < cList.size(); ++i) c2idx[cList[i]] = i;
  static SegTree streer, streec;
  streer.init(rList);
  streec.init(cList);
  for (int i = 0; i < nQuery; ++i) {
    int *q = query[i];
    if (q[0] == 0) {
      streer.update(0, 0, rList.size() - 1, r2idx[q[1]], r2idx[q[3]],
                    1LL * q[5] * (q[4] - q[2] + 1));
      streec.update(0, 0, cList.size() - 1, c2idx[q[2]], c2idx[q[4]],
                    1LL * q[5] * (q[3] - q[1] + 1));
    } else {
      long long rA = streer.get(0, 0, rList.size() - 1, 0, rList.size() - 1);
      long long rB = streer.get(0, 0, rList.size() - 1, 0, r2idx[q[3]]);
      long long rC = streer.get(0, 0, rList.size() - 1, 0, r2idx[q[1]] - 1);
      long long cB = streec.get(0, 0, cList.size() - 1, 0, c2idx[q[4]]);
      long long cC = streec.get(0, 0, cList.size() - 1, 0, c2idx[q[2]] - 1);
      printf("%I64d\n", -rA + rB - rC + cB - cC);
    }
  }
}
int main() {
  read();
  work();
  return 0;
}
