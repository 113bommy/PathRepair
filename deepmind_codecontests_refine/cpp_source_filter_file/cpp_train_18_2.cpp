#include <bits/stdc++.h>
const int maxn = 200000 + 10;
class BIT {
 private:
  int n;
  int bit[maxn];

 public:
  BIT(int size) {
    n = size;
    std::fill(bit, bit + size, 0);
  }
  void add(int x, int v) {
    while (x <= this->n) {
      bit[x] += v;
      x += ((x) & (-x));
    }
  }
  int query(int x) {
    int ans = 0;
    while (x) {
      ans += bit[x];
      x -= ((x) & (-x));
    }
    return ans;
  }
  int find_k(int k) {
    int bits = 0;
    int n = this->n;
    while (n) {
      n >>= 1;
      bits++;
    }
    int mask = 0;
    int cnt = 0;
    for (int i = bits - 1; i >= 0; i--) {
      mask += 1 << i;
      if (mask > this->n || cnt + bit[mask] >= k)
        mask -= (1 << i);
      else
        cnt += bit[mask];
    }
    return mask + 1;
  }
};
int n, pos[maxn];
struct TreeNode {
  int zeros, preadd, sufadd;
  long long presum, sufsum;
};
TreeNode seg[maxn * 4];
void build_tree(int node, int L, int R) {
  seg[node].zeros = R - L + 1;
  if (L == R) return;
  int M = L + (R - L) / 2;
  build_tree(node << 1, L, M);
  build_tree(node << 1 | 1, M + 1, R);
}
void push_down(int node, int L, int R) {
  int lch = node << 1;
  int rch = node << 1 | 1;
  int M = L + (R - L) / 2;
  if (seg[node].preadd) {
    seg[lch].preadd += seg[node].preadd;
    seg[rch].preadd += seg[node].preadd;
    seg[lch].presum += 1LL * seg[lch].zeros * seg[node].preadd;
    seg[rch].presum += 1LL * seg[rch].zeros * seg[node].preadd;
    seg[node].preadd = 0;
  }
  if (seg[node].sufadd) {
    seg[lch].sufadd += seg[node].sufadd;
    seg[rch].sufadd += seg[node].sufadd;
    seg[lch].sufsum += 1LL * seg[lch].zeros * seg[node].sufadd;
    seg[rch].sufsum += 1LL * seg[rch].zeros * seg[node].sufadd;
    seg[node].sufadd = 0;
  }
}
int qL, qR;
void add(int node, int L, int R, int type) {
  if (qL <= L && R <= qR) {
    if (type == 0) {
      seg[node].preadd += 1;
      seg[node].presum += seg[node].zeros;
    } else {
      seg[node].sufadd += 1;
      seg[node].sufsum += seg[node].zeros;
    }
    return;
  }
  push_down(node, L, R);
  int M = L + (R - L) / 2;
  if (qL <= M) add(node << 1, L, M, type);
  if (qR > M) add(node << 1 | 1, M + 1, R, type);
  int lch = node << 1;
  int rch = node << 1 | 1;
  seg[node].zeros = seg[lch].zeros + seg[rch].zeros;
  seg[node].presum = seg[lch].presum + seg[rch].presum;
  seg[node].sufsum = seg[lch].sufsum + seg[rch].sufsum;
}
void erase(int node, int L, int R, int p) {
  if (L == R) {
    memset(seg + node, 0, sizeof(TreeNode));
    return;
  }
  int M = L + (R - L) / 2;
  int lch = node << 1;
  int rch = node << 1 | 1;
  push_down(node, L, R);
  if (p <= M)
    erase(lch, L, M, p);
  else
    erase(rch, M + 1, R, p);
  seg[node].zeros = seg[lch].zeros + seg[rch].zeros;
  seg[node].presum = seg[lch].presum + seg[rch].presum;
  seg[node].sufsum = seg[lch].sufsum + seg[rch].sufsum;
}
long long query(int node, int L, int R, int type) {
  if (qL <= L && R <= qR) {
    if (type == 0)
      return seg[node].presum;
    else
      return seg[node].sufsum;
  }
  push_down(node, L, R);
  long long ans = 0;
  int M = L + (R - L) / 2;
  if (qL <= M) ans += query(node << 1, L, M, type);
  if (qR > M) ans += query(node << 1 | 1, M + 1, R, type);
  return ans;
}
int main() {
  scanf("%d", &n);
  BIT bit(n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    pos[a] = i;
  }
  build_tree(1, 1, n);
  long long inversion = 0;
  for (int i = 1; i <= n; i++) {
    const int &p = pos[i];
    inversion += i - 1 - bit.query(p);
    bit.add(p, 1);
    qL = p + 1;
    qR = n;
    if (qL <= qR) add(1, 1, n, 0);
    qL = 1;
    qR = p - 1;
    if (qL <= qR) add(1, 1, n, 1);
    erase(1, 1, n, p);
    long long ans = 0;
    int median = bit.find_k((i + 1) / 2);
    qL = 1;
    qR = median - 1;
    if (qL <= qR) {
      ans += query(1, 1, n, 0);
    }
    qL = median + 1;
    qR = n;
    if (qL <= qR) {
      ans += query(1, 1, n, 1);
    }
    printf("%lld ", inversion + ans);
  }
  printf("\n");
  return 0;
}
