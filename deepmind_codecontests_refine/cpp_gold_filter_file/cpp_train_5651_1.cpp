#include <bits/stdc++.h>
using namespace std;
struct Left {
  int x, time, pid, val;
  Left(int _a = 0, int _b = 0, int _c = 0) : x(_a), time(_b), val(_c) {
    pid = 0;
  };
  bool operator<(const Left &a) const {
    if (val != a.val) return val < a.val;
    if (x != a.x) return x < a.x;
    if (pid != a.pid) return pid < a.pid;
    if (time != a.time) return time < a.time;
    return false;
  }
};
set<Left> st1, st2, st3;
set<Left>::iterator it;
struct DD {
  int x, d, t, p, id;
  int start;
  bool operator<(const DD &b) const { return start < b.start; }
} dd[100005];
int pre[110000];
vector<int> path;
int main() {
  int N, L;
  while (scanf("%d%d", &N, &L) != EOF) {
    for (int i = 0; i < N; i++) {
      scanf("%d %d %d %d", &dd[i].x, &dd[i].d, &dd[i].t, &dd[i].p);
      dd[i].start = dd[i].x - dd[i].p;
      dd[i].id = i + 1;
    }
    memset(pre, -1, sizeof(pre));
    sort(dd, dd + N);
    int ans = L;
    st1.clear();
    st2.clear();
    st3.clear();
    st1.insert(Left(0, 0, 0));
    Left tar = Left(0, 0, 0);
    int id = 0;
    for (int i = 0; i < N; i++) {
      if (dd[i].start < 0) continue;
      while (st3.size() && st3.begin()->x <= dd[i].start) {
        Left tmp = *st3.begin();
        st3.erase(st3.begin());
        tmp.val = tmp.x + tmp.time;
        it = st2.find(tmp);
        st2.erase(it);
        tmp.val = tmp.time - tmp.x;
        st1.insert(tmp);
      }
      long long runT = dd[i].start, pid = 0;
      if (st1.size()) {
        if (st1.begin()->val + dd[i].start < runT) {
          runT = st1.begin()->val + dd[i].start;
          pid = st1.begin()->pid;
        }
      }
      if (st2.size()) {
        if (st2.begin()->val - dd[i].start < runT) {
          runT = st2.begin()->val - dd[i].start;
          pid = st2.begin()->pid;
        }
      }
      long long tarT = runT + dd[i].p + dd[i].t, x = dd[i].x + dd[i].d;
      pre[dd[i].id] = pid;
      if (tarT + L - x < ans) {
        ans = tarT + L - x;
        id = dd[i].id;
      }
      Left tmp;
      tmp.x = x;
      tmp.time = tarT;
      tmp.pid = dd[i].id;
      tmp.val = 0;
      st3.insert(tmp);
      tmp.val = tmp.x + tmp.time;
      st2.insert(tmp);
    }
    printf("%d\n", ans);
    path.clear();
    while (id > 0) {
      path.push_back(id);
      id = pre[id];
    }
    printf("%d\n", (int)path.size());
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++)
      printf("%d%s", path[i], (i == path.size() - 1 ? "\n" : " "));
  }
}
