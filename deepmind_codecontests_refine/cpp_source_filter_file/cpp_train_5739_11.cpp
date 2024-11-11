#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> inst;
int n;
bool a[100005];
namespace worker {
vector<tuple<int, int, int>> mask_op;
vector<unsigned> masks;
bool vis[128];
int prev_op[128], dist[128];
void work();
void init() {
  masks.push_back(0b111000);
  mask_op.emplace_back(1, 2, 3);
  masks.push_back(0b011100);
  mask_op.emplace_back(2, 3, 4);
  masks.push_back(0b001110);
  mask_op.emplace_back(3, 4, 5);
  masks.push_back(0b000111);
  mask_op.emplace_back(4, 5, 6);
  masks.push_back(0b000011);
  mask_op.emplace_back(5, 6, 7);
  masks.push_back(0b000001);
  mask_op.emplace_back(6, 7, 8);
  masks.push_back(0b101010);
  mask_op.emplace_back(1, 3, 5);
  masks.push_back(0b010101);
  mask_op.emplace_back(2, 4, 6);
  masks.push_back(0b001010);
  mask_op.emplace_back(3, 5, 7);
  masks.push_back(0b000101);
  mask_op.emplace_back(4, 6, 8);
  masks.push_back(0b000010);
  mask_op.emplace_back(5, 7, 9);
  masks.push_back(0b100100);
  mask_op.emplace_back(1, 4, 7);
  masks.push_back(0b010010);
  mask_op.emplace_back(2, 5, 8);
  masks.push_back(0b001001);
  mask_op.emplace_back(3, 6, 9);
  masks.push_back(0b000100);
  mask_op.emplace_back(4, 7, 10);
  masks.push_back(0b100010);
  mask_op.emplace_back(1, 5, 9);
  masks.push_back(0b010001);
  mask_op.emplace_back(2, 6, 10);
  masks.push_back(0b100001);
  mask_op.emplace_back(1, 6, 11);
  work();
}
void work() {
  vis[0] = true;
  int np = masks.size();
  queue<unsigned> q;
  q.push(0);
  while (q.size()) {
    unsigned cur = q.front();
    q.pop();
    for (int i = 0; i < (np); i++) {
      if (!vis[cur ^ masks[i]]) {
        vis[cur ^ masks[i]] = true;
        prev_op[cur ^ masks[i]] = i;
        dist[cur ^ masks[i]] = dist[cur] + 1;
        q.push(cur ^ masks[i]);
      }
    }
  }
  for (int i = 0; i < (1 << 6); i++) {
    if (!vis[i] || dist[i] > 2) ((void)0);
    ;
  }
}
void apply_instr(int pos, int id) {
  int x, y, z;
  tie(x, y, z) = mask_op[id];
  x += pos;
  y += pos;
  z += pos;
  a[x - 1] ^= 1;
  a[y - 1] ^= 1;
  a[z - 1] ^= 1;
  inst.emplace_back(x, y, z);
}
void eliminate(int pos) {
  unsigned mask = 0;
  for (int i = pos; i < pos + 6; i++) mask = mask << 1 | a[i];
  while (mask) {
    apply_instr(pos, prev_op[mask]);
    mask ^= masks[prev_op[mask]];
  }
}
};  // namespace worker
namespace searcher {
vector<unsigned> masks;
vector<tuple<int, int, int>> mask_op;
bool vis[1 << 14];
int prev_op[1 << 14];
void init(int n) {
  for (int d = 1; d < 12; d++) {
    for (int l = 0; l < 12; l++) {
      int m = l + d, r = m + d;
      if (r >= n) break;
      masks.push_back(1u << l | 1u << m | 1u << r);
      mask_op.emplace_back(l + 1, m + 1, r + 1);
    }
  }
  vis[0] = true;
  queue<unsigned> q;
  q.push(0);
  int np = masks.size();
  while (q.size()) {
    unsigned cur = q.front();
    q.pop();
    for (int i = 0; i < (np); i++) {
      unsigned next = cur ^ masks[i];
      if (vis[next]) continue;
      vis[next] = true;
      prev_op[next] = i;
      q.push(next);
    }
  }
}
bool search(int off, int len) {
  init(len);
  unsigned mask = 0;
  for (int i = off + len - 1; i >= off; i--) mask = mask << 1 | a[i];
  ((void)0);
  ;
  if (!vis[mask]) return false;
  while (mask) {
    int x, y, z;
    tie(x, y, z) = mask_op[prev_op[mask]];
    mask ^= masks[prev_op[mask]];
    inst.emplace_back(off + x, off + y, off + z);
  }
  return true;
}
}  // namespace searcher
int main() {
  worker::init();
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) {
    int x;
    scanf("%d", &x);
    a[i] = x;
  }
  int l = 0;
  while (n - l > 12) {
    worker::eliminate(l);
    l += 6;
  }
  if (searcher::search(l, n - l)) {
    puts("YES");
    printf("%d\n", (int)inst.size());
    for (auto op : inst) {
      int x, y, z;
      tie(x, y, z) = op;
      printf("%d %d %d\n", x, y, z);
    }
  } else {
    puts("NO");
  }
  return 0;
}
