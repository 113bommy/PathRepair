#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
vector<int> tim;
map<int, int> ntim;
struct task {
  int a, t, x, i;
};
bool operator<(task A, task B) {
  return (A.x < B.x) || (A.x == B.x && A.i < B.i);
}
int n;
vector<task> tsk;
int tre[maxn];
int res[maxn];
void add(int x, int val) {
  for (; x < maxn; x = (x | (x + 1))) {
    tre[x] += val;
  }
}
int sum(int r) {
  int res = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    res += tre[r];
  }
  return res;
}
int main() {
  scanf("%d", &n);
  tsk.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &tsk[i].a, &tsk[i].t, &tsk[i].x);
    tsk[i].i = i;
    tim.push_back(tsk[i].t);
  }
  sort(tim.begin(), tim.end());
  stable_sort(tsk.begin(), tsk.end());
  tim.resize(unique(tim.begin(), tim.end()) - tim.begin());
  for (int i = 0; i < (int)tim.size(); ++i) {
    ntim[tim[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    int val = tsk[i].x;
    int j = i;
    for (; i < n && tsk[i].x == val; ++i) {
      if (tsk[i].a == 1) {
        add(ntim[tsk[i].t], 1);
      } else if (tsk[i].a == 2) {
        add(ntim[tsk[i].t], -1);
      } else {
        res[tsk[i].i] = sum(ntim[tsk[i].t]) + 1;
      }
    }
    for (; j < i; ++j) {
      if (tsk[i].a == 1) {
        add(ntim[tsk[i].t], -1);
      } else if (tsk[i].a == 2) {
        add(ntim[tsk[i].t], +1);
      }
    }
    --i;
  }
  for (int i = 0; i < n; ++i) {
    if (res[i] > 0) {
      printf("%d\n", res[i] - 1);
    }
  }
}
