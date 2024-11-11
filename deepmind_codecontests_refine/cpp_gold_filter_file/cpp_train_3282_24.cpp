#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int ans[maxn];
struct Q {
  int x, t, id, val;
  Q(int val = 0, int t = 0, int x = 0, int id = 0)
      : val(val), t(t), id(id), x(x){};
};
bool cmp1(const Q &a1, const Q &a2) { return a1.x < a2.x; }
bool cmp2(const Q &a1, const Q &a2) { return a1.id < a2.id; }
int N;
int t[maxn];
void add(int pos, int val) {
  for (; pos <= N; pos |= (pos + 1)) {
    t[pos] += val;
  }
}
int get(int pos) {
  int ret = 0;
  for (; pos > 0; pos = (pos & (pos + 1)) - 1) {
    ret += t[pos];
  }
  return ret;
}
Q quer[maxn];
Q cur_q[maxn];
int cur_size = 0;
void perform(int st, int fi) {
  cur_size = 0;
  for (int i = st; i <= fi; i++) {
    cur_q[cur_size++] = quer[i];
  }
  vector<int> times;
  times.clear();
  times.resize(cur_size);
  sort(cur_q, cur_q + cur_size, cmp2);
  for (int i = 0; i < cur_size; i++) {
    times[i] = cur_q[i].t;
  }
  sort(times.begin(), times.end());
  N = (int)times.size() + 2;
  for (int i = 0; i <= N; i++) t[i] = 0;
  for (int i = 0; i < cur_size; i++) {
    int poss =
        lower_bound(times.begin(), times.end(), cur_q[i].t) - times.begin();
    poss++;
    if (cur_q[i].val == 1) {
      add(poss, 1);
    } else if (cur_q[i].val == 2) {
      add(poss, -1);
    } else {
      ans[cur_q[i].id] = get(poss);
    }
  }
}
int main() {
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    ans[i] = -1;
    int v, t, x;
    scanf("%d %d %d", &v, &t, &x);
    quer[i] = Q(v, t, x, i);
  }
  sort(quer, quer + n, cmp1);
  int last = 0;
  for (int i = 1; i <= n; i++) {
    if (quer[i].x != quer[i - 1].x) {
      perform(last, i - 1);
      last = i;
    }
  }
  perform(last, n - 1);
  for (int i = 0; i < n; i++)
    if (ans[i] != -1) printf("%d\n", ans[i]);
  return 0;
}
