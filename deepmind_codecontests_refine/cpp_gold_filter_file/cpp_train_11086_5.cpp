#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
void setup() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
}
const int MN = 1 << 19;
struct seg_tree {
  vector<int> arr;
  seg_tree() { arr = vector<int>(2 * MN + 100, INF); }
  int upd(int i, int v, int loc = 1, int x = 0, int y = MN - 1) {
    if (y < i || i < x) return arr[loc];
    if (x == y) {
      return arr[loc] = v;
    }
    return arr[loc] = min(upd(i, v, 2 * loc, x, x + (y - x + 1) / 2 - 1),
                          upd(i, v, 2 * loc + 1, x + (y - x + 1) / 2, y));
  }
  int rmq(int i, int j, int loc = 1, int x = 0, int y = MN - 1) {
    if (y < i || x > j) return INF;
    if (i <= x && y <= j) return arr[loc];
    return min(rmq(i, j, 2 * loc, x, x + (y - x + 1) / 2 - 1),
               rmq(i, j, 2 * loc + 1, x + (y - x + 1) / 2, y));
  }
};
int find(seg_tree &seg, int i, int k) {
  int lo = 0, hi = i;
  int ans = 0;
  while (lo <= hi) {
    int mi = (lo + hi) / 2;
    int lv = seg.rmq(mi, i);
    if (lv <= k) {
      ans = mi;
      lo = mi + 1;
    } else
      hi = mi - 1;
  }
  return ans;
}
int look(vector<int> &all, int v) {
  return lower_bound(all.begin(), all.end(), v) - all.begin();
}
const int MAXQ = 200005;
int N, Q;
seg_tree rows, cols;
int L[MAXQ], LC[MAXQ];
int R[MAXQ], RC[MAXQ];
char T[MAXQ];
vector<bool> ater, atec;
int main() {
  setup();
  cin >> N >> Q;
  rows.upd(0, 0);
  cols.upd(0, 0);
  vector<int> all;
  all.push_back(0);
  for (int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i] >> T[i];
    all.push_back(L[i]);
    all.push_back(R[i]);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  ater.resize(all.size());
  atec.resize(all.size());
  for (int i = 0; i < Q; i++) {
    int LC = look(all, L[i]);
    int RC = look(all, R[i]);
    if (T[i] == 'U') {
      if (atec[LC] || ater[RC]) {
        cout << 0 << "\n";
        continue;
      }
      int b = find(rows, RC, LC);
      cols.upd(LC, b);
      cout << all[RC] - all[b] << "\n";
      atec[LC] = true;
    } else {
      if (ater[RC] || atec[LC]) {
        cout << 0 << "\n";
        continue;
      }
      int b = find(cols, LC, RC);
      rows.upd(RC, b);
      cout << all[LC] - all[b] << "\n";
      ater[RC] = true;
    }
  }
}
