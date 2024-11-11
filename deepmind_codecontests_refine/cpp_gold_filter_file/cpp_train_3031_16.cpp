#include <bits/stdc++.h>
using namespace std;
struct arr {
  int a[9];
  arr() { memset(a, 0, sizeof a); }
  void out(int k) {
    if (k > 1000) return;
    printf("%d =", k);
    for (int i = 0; i < 9; i++) printf(" %d", a[i]);
    puts("");
  }
  bool chk() {
    if (a[0] == 3 && a[1] == 0 && a[2] == 2 && a[3] == 3 && a[4] == 0 &&
        a[5] == -1 && a[6] == 4 && a[7] == 1 && a[8] == 0)
      return true;
    return false;
  }
} beg;
struct classcomp {
  bool operator()(arr a, arr b) const {
    for (int i = 0; i < 9; i++)
      if (a.a[i] != b.a[i]) return a.a[i] < b.a[i];
    return false;
  }
};
set<arr, classcomp> a;
int pos[5], step[5], grab[5], ans, tot;
bool f;
void dfs(arr now) {
  if (a.find(now) != a.end()) return;
  ans = max(ans, max(max(now.a[0], now.a[3]), now.a[6]));
  a.insert(now);
  arr next = now;
  if (now.a[5] != 1 && now.a[8] != 1) {
    if (!now.a[1] && now.a[2] <= 0) {
      for (int i = max(1, now.a[0] - step[1]); i <= now.a[0] + step[1]; i++)
        if (now.a[3] != i && now.a[6] != i) {
          next.a[1] = 1;
          next.a[0] = i;
          if (now.a[2] == 2) {
            next.a[3] = i;
            if (now.a[5] == 3) next.a[6] = i;
          } else if (now.a[2] == 3) {
            next.a[6] = i;
            if (now.a[8] == 2) next.a[3] = i;
          }
          dfs(next);
          next.a[1] = 0;
          next.a[0] = now.a[0];
          next.a[3] = now.a[3];
          next.a[6] = now.a[6];
        }
    }
    if (!now.a[2]) {
      if ((now.a[3] == now.a[0] - 1 || now.a[3] == now.a[0] + 1) &&
          (now.a[8] != 2)) {
        next.a[2] = 2;
        next.a[3] = now.a[0];
        if (now.a[5] == 3) next.a[6] = now.a[0];
        dfs(next);
        next.a[2] = 0;
        next.a[3] = now.a[3];
        next.a[6] = now.a[6];
      }
      if ((now.a[6] == now.a[0] - 1 || now.a[6] == now.a[0] + 1) &&
          (now.a[5] != 3)) {
        next.a[2] = 3;
        next.a[6] = now.a[0];
        if (now.a[8] == 2) next.a[3] = now.a[0];
        dfs(next);
        next.a[2] = 0;
        next.a[6] = now.a[6];
        next.a[3] = now.a[3];
      }
    } else if (now.a[2] == 2) {
      for (int i = max(1, now.a[0] - grab[1]); i <= now.a[0] + grab[1]; i++)
        if (now.a[0] != i && now.a[6] != i) {
          next.a[3] = i;
          next.a[2] = -1;
          if (now.a[5] == 3) next.a[6] = i;
          dfs(next);
          next.a[2] = now.a[2];
          next.a[3] = now.a[3];
          next.a[6] = now.a[6];
        }
    } else if (now.a[2] == 3) {
      for (int i = max(1, now.a[0] - grab[1]); i <= now.a[0] + grab[1]; i++)
        if (now.a[0] != i && now.a[3] != i) {
          next.a[6] = i;
          next.a[2] = -1;
          if (now.a[8] == 2) next.a[3] = i;
          dfs(next);
          next.a[2] = 3;
          next.a[3] = now.a[3];
          next.a[6] = now.a[6];
        }
    }
  }
  if (now.a[2] != 2 && now.a[8] != 2) {
    if (!now.a[4] && now.a[5] <= 0) {
      for (int i = max(1, now.a[3] - step[2]); i <= now.a[3] + step[2]; i++)
        if (now.a[0] != i && now.a[6] != i) {
          next.a[4] = 1;
          next.a[3] = i;
          if (now.a[5] == 1) {
            next.a[0] = i;
            if (now.a[2] == 3) next.a[6] = i;
          } else if (now.a[5] == 3) {
            next.a[6] = i;
            if (now.a[8] == 1) next.a[0] = i;
          }
          dfs(next);
          next.a[4] = 0;
          next.a[3] = now.a[3];
          next.a[6] = now.a[6];
          next.a[0] = now.a[0];
        }
    }
    if (!now.a[5]) {
      if ((now.a[0] == now.a[3] - 1 || now.a[0] == now.a[3] + 1) &&
          now.a[8] != 1) {
        next.a[5] = 1;
        next.a[0] = now.a[3];
        if (now.a[2] == 3) next.a[6] = now.a[3];
        dfs(next);
        next.a[5] = 0;
        next.a[0] = now.a[0];
        next.a[6] = now.a[6];
      }
      if ((now.a[6] == now.a[3] - 1 || now.a[6] == now.a[3] + 1) &&
          now.a[2] != 3) {
        next.a[5] = 3;
        next.a[6] = now.a[3];
        if (now.a[8] == 1) next.a[0] = now.a[3];
        dfs(next);
        next.a[5] = 0;
        next.a[6] = now.a[6];
        next.a[0] = now.a[0];
      }
    } else if (now.a[5] == 1) {
      for (int i = max(1, now.a[3] - grab[2]); i <= now.a[3] + grab[2]; i++)
        if (now.a[3] != i && now.a[6] != i) {
          next.a[0] = i;
          next.a[5] = -1;
          if (now.a[2] == 3) next.a[6] = i;
          dfs(next);
          next.a[6] = now.a[6];
          next.a[5] = now.a[5];
          next.a[0] = now.a[0];
        }
    } else if (now.a[5] == 3) {
      for (int i = max(1, now.a[3] - grab[2]); i <= now.a[3] + grab[2]; i++)
        if (now.a[0] != i && now.a[3] != i) {
          next.a[6] = i;
          next.a[5] = -1;
          if (now.a[8] == 1) next.a[0] = i;
          dfs(next);
          next.a[5] = now.a[5];
          next.a[6] = now.a[6];
          next.a[0] = now.a[0];
        }
    }
  }
  if (now.a[2] != 3 && now.a[5] != 3) {
    if (!now.a[7] && now.a[8] <= 0) {
      for (int i = max(1, now.a[6] - step[3]); i <= now.a[6] + step[3]; i++)
        if (now.a[0] != i && now.a[3] != i) {
          next.a[7] = 1;
          next.a[6] = i;
          if (now.a[8] == 1) {
            next.a[0] = i;
            if (now.a[2] == 2) next.a[3] = i;
          } else if (now.a[8] == 2) {
            next.a[3] = i;
            if (now.a[5] == 1) next.a[0] = i;
          }
          dfs(next);
          next.a[7] = 0;
          next.a[6] = now.a[6];
          next.a[0] = now.a[0];
          next.a[3] = now.a[3];
        }
    }
    if (!now.a[8]) {
      if ((now.a[0] == now.a[6] - 1 || now.a[0] == now.a[6] + 1) &&
          now.a[5] != 1) {
        next.a[8] = 1;
        next.a[0] = now.a[6];
        if (now.a[2] == 2) next.a[3] = now.a[6];
        dfs(next);
        next.a[8] = 0;
        next.a[0] = now.a[0];
        next.a[3] = now.a[3];
      }
      if ((now.a[3] == now.a[6] - 1 || now.a[3] == now.a[6] + 1) &&
          now.a[2] != 2) {
        next.a[8] = 2;
        next.a[3] = now.a[6];
        if (now.a[5] == 1) next.a[0] = now.a[6];
        dfs(next);
        next.a[8] = 0;
        next.a[3] = now.a[3];
        next.a[0] = now.a[0];
      }
    } else if (now.a[8] == 1) {
      for (int i = max(1, now.a[6] - grab[3]); i <= now.a[6] + grab[3]; i++)
        if (now.a[3] != i && now.a[6] != i) {
          next.a[0] = i;
          next.a[8] = -1;
          if (now.a[2] == 2) next.a[3] = i;
          dfs(next);
          next.a[0] = now.a[0];
          next.a[3] = now.a[3];
          next.a[8] = now.a[8];
        }
    } else if (now.a[8] == 2) {
      for (int i = max(1, now.a[6] - grab[3]); i <= now.a[6] + grab[3]; i++)
        if (now.a[0] != i && now.a[3] != i) {
          next.a[3] = i;
          next.a[8] = -1;
          if (now.a[5] == 1) next.a[0] = i;
          dfs(next);
          next.a[8] = 2;
          next.a[0] = now.a[0];
          next.a[3] = now.a[3];
        }
    }
  }
}
int main() {
  for (int i = 1; i <= 3; i++) cin >> pos[i] >> step[i] >> grab[i];
  beg.a[0] = pos[1];
  beg.a[3] = pos[2];
  beg.a[6] = pos[3];
  dfs(beg);
  printf("%d\n", ans);
  return 0;
}
