#include <bits/stdc++.h>
using namespace std;
int n;
struct gripper {
  long long weight, dist, power, rng;
  gripper() {}
  gripper(long long a, long long b, long long c, long long d)
      : weight(a), dist(b), power(c), rng(d) {}
  bool operator<(const gripper& gr) const { return dist < gr.dist; }
};
vector<gripper> vec;
class segtree {
 public:
  int id[(1 << 18) * 2];
  void init() { fill(id, id + (1 << 18) * 2, n); }
  void update(int pos) {
    id[pos + (1 << 18) - 1] = pos;
    int cur = pos + (1 << 18) - 1;
    while (cur > 0) {
      cur = (cur - 1) / 2;
      if (vec[id[cur * 2 + 1]].weight < vec[id[cur * 2 + 2]].weight) {
        id[cur] = id[cur * 2 + 1];
      } else {
        id[cur] = id[cur * 2 + 2];
      }
    }
  }
  void del(int pos) {
    id[pos + (1 << 18) - 1] = n;
    int cur = pos + (1 << 18) - 1;
    while (cur > 0) {
      cur = (cur - 1) / 2;
      if (vec[id[cur * 2 + 1]].weight < vec[id[cur * 2 + 2]].weight) {
        id[cur] = id[cur * 2 + 1];
      } else {
        id[cur] = id[cur * 2 + 2];
      }
    }
  }
  int get(int a, int b, int k, int l, int r) {
    if (r < a || b < l) return n;
    if (a <= l && r <= b) return id[k];
    int lb = get(a, b, k * 2 + 1, l, (l + r) / 2);
    int ub = get(a, b, k * 2 + 2, (l + r) / 2 + 1, r);
    if (vec[lb].weight < vec[ub].weight)
      return lb;
    else
      return ub;
  }
} seg;
int main() {
  srand((unsigned int)time(NULL));
  long long sx, sy, power, rng;
  scanf("%lld %lld %lld %lld", &sx, &sy, &power, &rng);
  scanf("%d", &n);
  vector<int> lis;
  for (int i = 0; i < n; i++) {
    long long x, y, w, p, r;
    scanf("%lld %lld %lld %lld %lld", &x, &y, &w, &p, &r);
    long long dist = (sx - x) * (sx - x) + (sy - y) * (sy - y);
    long long weight = w;
    long long power2 = p;
    long long rng2 = r * r;
    vec.push_back(gripper(weight, dist, power2, rng2));
    lis.push_back(dist);
  }
  sort(vec.begin(), vec.end());
  sort(lis.begin(), lis.end());
  vec[n].weight = 1e18;
  seg.init();
  for (int i = 0; i < n; i++) seg.update(i);
  queue<gripper> cur;
  cur.push(gripper(0, 0, power, rng * rng));
  int tot = 0;
  while (!cur.empty()) {
    gripper gr = cur.front();
    cur.pop();
    int id = upper_bound(lis.begin(), lis.end(), gr.rng) - lis.begin();
    id--;
    while (1) {
      int nxt = seg.get(0, id, 0, 0, (1 << 18) - 1);
      if (gr.power < vec[nxt].weight) break;
      cur.push(vec[nxt]);
      tot++;
      seg.del(nxt);
    }
  }
  printf("%d\n", tot);
}
