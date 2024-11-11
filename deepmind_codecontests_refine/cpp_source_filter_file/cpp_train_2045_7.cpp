#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
const long long int INF = 123456789987654321;
int N;
vector<int> arr;
vector<vector<int> > cycle;
vector<int> vis;
int cycle_num;
void get_cycle() {
  vis = vector<int>(N, 0);
  cycle_num = 0;
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      cycle.push_back(vector<int>());
      int now = i;
      while (!vis[now]) {
        vis[now] = 1;
        cycle[cycle_num].push_back(now);
        now = arr[now];
      }
      cycle_num++;
    }
  }
}
vector<vector<int> > ans_b, ans_c;
vector<int> remain;
void go(int cycle_id, int len) {
  vector<int> b, c;
  for (int i = cycle[cycle_id].size() - len; i < cycle[cycle_id].size(); i++) {
    b.push_back(cycle[cycle_id][i]);
  }
  for (int i = cycle[cycle_id].size() - len; i < cycle[cycle_id].size(); i++) {
    if (i == cycle[cycle_id].size() - 1) {
      c.push_back(b[0]);
    } else {
      c.push_back(b[i - (int)cycle[cycle_id].size() + len + 1]);
    }
  }
  ans_b.push_back(b);
  ans_c.push_back(c);
  if (cycle[cycle_id].size() == len) {
    remain[cycle_id] = 0;
    return;
  }
  cycle[cycle_id].resize(cycle[cycle_id].size() - len + 1);
}
vector<int> cycle2, cycle3;
void go2(int cycle_id1, int len1, int cycle_id2, int len2) {
  vector<int> b, c;
  for (int i = cycle[cycle_id1].size() - len1; i < cycle[cycle_id1].size();
       i++) {
    b.push_back(cycle[cycle_id1][i]);
  }
  for (int i = cycle[cycle_id1].size() - len1; i < cycle[cycle_id1].size();
       i++) {
    if (i == cycle[cycle_id1].size() - 1) {
      c.push_back(b[0]);
    } else {
      c.push_back(b[i - (int)cycle[cycle_id1].size() + len1 + 1]);
    }
  }
  for (int i = cycle[cycle_id2].size() - len2; i < cycle[cycle_id2].size();
       i++) {
    b.push_back(cycle[cycle_id2][i]);
  }
  for (int i = cycle[cycle_id2].size() - len2; i < cycle[cycle_id2].size();
       i++) {
    if (i == cycle[cycle_id2].size() - 1) {
      c.push_back(b[len1]);
    } else {
      c.push_back(b[len1 + i - (int)cycle[cycle_id2].size() + len2 + 1]);
    }
  }
  ans_b.push_back(b);
  ans_c.push_back(c);
  if (cycle[cycle_id1].size() == len1) {
    remain[cycle_id1] = 0;
  } else {
    cycle[cycle_id1].resize(cycle[cycle_id1].size() - len1 + 1);
  }
  if (cycle[cycle_id2].size() == len2) {
    remain[cycle_id2] = 0;
  } else {
    cycle[cycle_id2].resize(cycle[cycle_id2].size() - len2 + 1);
  }
}
void print() {
  for (int i = 0; i < cycle.size(); i++) {
    if (!remain[i]) continue;
    for (int j = 0; j < cycle[i].size(); j++) {
      cout << cycle[i][j] << ' ';
    }
    cout << endl;
  }
}
void solve() {
  remain = vector<int>(cycle_num, 1);
  for (int i = 0; i < cycle_num; i++) {
    if (cycle[i].size() == 1) remain[i] = 0;
    while (remain[i] && cycle[i].size() > 5) {
      go(i, 5);
    }
    if (remain[i] && cycle[i].size() >= 4) {
      go(i, cycle[i].size());
    }
  }
  for (int i = 0; i < cycle_num; i++) {
    if (remain[i] && cycle[i].size() == 2) {
      cycle2.push_back(i);
    }
    if (remain[i] && cycle[i].size() == 3) {
      cycle3.push_back(i);
    }
  }
  int mini = inf, minp = 0;
  for (int i = 0; i < (int)cycle3.size() / 2; i++) {
    int cnt = i;
    if ((int)cycle3.size() - 2 * i > (int)cycle2.size() + i) {
      cnt += (int)cycle3.size() - 2 * i;
      if (mini > cnt) {
        mini = cnt;
        minp = i;
      }
    } else {
      cnt += (int)cycle3.size() - 2 * i;
      cnt += 2 * ((int)cycle2.size() + i - (int)cycle3.size() + 2 * i);
      if (mini > cnt) {
        mini = cnt;
        minp = i;
      }
    }
  }
  for (int i = 0; i < minp; i++) {
    go2(cycle3[2 * i], 2, cycle3[2 * i + 1], 3);
  }
  cycle2.clear();
  cycle3.clear();
  for (int i = 0; i < cycle.size(); i++) {
    if (remain[i] && cycle[i].size() == 2) {
      cycle2.push_back(i);
    }
    if (remain[i] && cycle[i].size() == 3) {
      cycle3.push_back(i);
    }
  }
  for (int i = 0; i < min(cycle2.size(), cycle3.size()); i++) {
    go2(cycle2[i], 2, cycle3[i], 3);
  }
  if (cycle2.size() > cycle3.size()) {
    cycle2.clear();
    for (int i = 0; i < cycle.size(); i++) {
      if (remain[i]) cycle2.push_back(i);
    }
    for (int i = 0; i < cycle2.size() / 2; i++) {
      go2(cycle2[2 * i], 2, cycle2[2 * i + 1], 2);
    }
    if (cycle2.size() % 2) {
      go(cycle2.back(), 2);
    }
  }
  if (cycle2.size() < cycle3.size()) {
    for (int i = 0; i < cycle.size(); i++) {
      if (remain[i]) {
        go(i, cycle[i].size());
      }
    }
  }
  printf("%d\n", ans_b.size());
  for (int i = 0; i < ans_b.size(); i++) {
    printf("%d\n", ans_b[i].size());
    for (int j = 0; j < ans_b[i].size(); j++) {
      printf("%d ", ans_b[i][j] + 1);
    }
    printf("\n");
    for (int j = 0; j < ans_c[i].size(); j++) {
      printf("%d ", ans_c[i][j] + 1);
    }
    printf("\n");
  }
}
int main() {
  scanf("%d", &N);
  arr.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
    arr[i]--;
  }
  get_cycle();
  solve();
}
