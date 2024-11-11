#include <bits/stdc++.h>
using namespace std;
struct _d {
  int r1, c1, r2, c2;
};
int n, m;
char arr[500][501];
bool ans[600000];
_d queries[600000];
bitset<500> DPU[500][500], DPD[500][500];
void dnc(int l, int r, vector<int> &qid) {
  if (l > r) return;
  int mid = (l + r) / 2;
  vector<int> ql, qr;
  for (int i = 0; i < qid.size(); i++) {
    if (queries[qid[i]].r2 < mid) {
      ql.push_back(qid[i]);
      qid[i] = qid.back(), qid.pop_back(), --i;
    } else if (queries[qid[i]].r1 > mid) {
      qr.push_back(qid[i]);
      qid[i] = qid.back(), qid.pop_back(), --i;
    }
  }
  if (!qid.empty()) {
    for (int i = m - 1; i >= 0; i--) {
      DPU[mid][i] = i != m - 1 && arr[mid][i + 1] == '.' ? DPU[mid][i + 1]
                                                         : bitset<500>();
      DPU[mid][i][i] = 1;
    }
    for (int i = 0; i < m; i++) {
      DPD[mid][i] =
          i && arr[mid][i - 1] == '.' ? DPD[mid][i - 1] : bitset<500>();
      DPD[mid][i][i] = 1;
    }
    for (int i = mid - 1; i >= l; i--) {
      for (int j = m - 1; j >= 0; j--) {
        DPU[i][j] = arr[i + 1][j] == '.' ? DPU[i + 1][j] : bitset<500>();
        if (j != m - 1 && arr[i][j + 1] == '.') DPU[i][j] |= DPU[i][j + 1];
      }
    }
    for (int i = mid + 1; i <= r; i++) {
      for (int j = 0; j < m; j++) {
        DPD[i][j] = arr[i - 1][j] == '.' ? DPD[i - 1][j] : bitset<500>();
        if (j && arr[i][j - 1] == '.') DPD[i][j] |= DPD[i][j - 1];
      }
    }
    for (int i : qid) {
      auto cq = queries[i];
      ans[i] = (DPU[cq.r1][cq.c1] & DPD[cq.r2][cq.c2]).any();
    }
  }
  if (!ql.empty()) dnc(l, mid - 1, ql);
  if (!qr.empty()) dnc(mid + 1, r, qr);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", arr[i]);
  int q;
  scanf("%d", &q);
  vector<int> qid(q);
  for (int i = 0; i < q; i++) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    queries[i] = {r1 - 1, c1 - 1, r2 - 1, c2 - 1};
    qid[i] = i;
  }
  dnc(0, n - 1, qid);
  for (int i = 0; i < q; i++) printf(ans[i] ? "Yes\n" : "No\n");
  return 0;
}
