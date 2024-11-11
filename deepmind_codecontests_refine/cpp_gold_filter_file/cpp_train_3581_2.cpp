#include <bits/stdc++.h>
using namespace std;
int arr[300005];
int block[605];
int blk_sz;
void update(int idx, int idy, vector<int>& pos) {
  int temp = arr[idx];
  arr[idx] = arr[idy];
  arr[idy] = temp;
  int blockNumber = idx / blk_sz;
  block[blockNumber] = 0;
  for (int i = blockNumber * blk_sz;
       i < min((int)pos.size(), (blockNumber * blk_sz) + blk_sz); i++) {
    if (i % blk_sz != 0 && pos[i - 1] > pos[i]) block[blockNumber]++;
  }
  blockNumber = idy / blk_sz;
  block[blockNumber] = 0;
  for (int i = blockNumber * blk_sz;
       i < min((int)pos.size(), (blockNumber * blk_sz) + blk_sz); i++) {
    if (i % blk_sz != 0 && pos[i - 1] > pos[i]) block[blockNumber]++;
  }
}
int query(int l, int r, vector<int>& pos, vector<int>& in) {
  int ct = 0;
  int lst = -1;
  int ql = l, qr = r;
  while (l < r and l % blk_sz != 0 and l != 0) {
    if (pos[l] < lst) ct++;
    lst = pos[l];
    l++;
  }
  while (l + blk_sz <= r) {
    ct += block[l / blk_sz];
    if ((l - 1) >= ql && (l - 1) <= qr && pos[l] < pos[l - 1]) ct++;
    l += blk_sz;
    lst = pos[l - 1];
  }
  while (l <= r) {
    if (pos[l] < lst) ct++;
    lst = pos[l];
    l++;
  }
  return ct;
}
void preprocess(vector<int>& input, vector<int>& pos, int n) {
  int blk_idx = -1;
  blk_sz = sqrt(n);
  int lst = -1;
  for (int i = 0; i < n; i++) {
    arr[i] = i;
    if (i % blk_sz == 0) {
      blk_idx++;
    } else {
      if (pos[i - 1] > pos[i]) block[blk_idx]++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> in;
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    v--;
    in.push_back(v);
    pos[v] = i;
  }
  preprocess(in, pos, n);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int p;
    cin >> p;
    int x;
    cin >> x;
    int y;
    cin >> y;
    x--;
    y--;
    if (p == 2) {
      int temp = in[x];
      in[x] = in[y];
      in[y] = temp;
      pos[in[y]] = y;
      pos[in[x]] = x;
      update(in[x], in[y], pos);
    } else {
      cout << 1 + query(x, y, pos, in) << '\n';
    }
  }
}
