#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[1010];
int f[1010], t[1010], v[1010];
int head[1010];
int ans = 0;
struct EDGE {
  int to;
  int val;
  int next;
} edge[2010];
int count_t = 0;
void add_edge(int from, int to, int val) {
  edge[++count_t].to = to;
  edge[count_t].val = val;
  edge[count_t].next = head[from];
  head[from] = count_t;
}
int get_a_child(int root, int father) {
  if (edge[head[root]].next == 0) return root;
  for (EDGE e = edge[head[root]]; e.next != -1; e = edge[e.next]) {
    if (e.to != father) {
      get_a_child(e.to, root);
      break;
    }
  }
}
void handle(int from, int to, int val, int flag) {
  int left_one = 0, left_two = 0, right_one = 0, right_two = 0;
  if (cnt[from] >= 3) {
    int l_cnt = 0;
    for (EDGE e = edge[head[from]]; e.next != -1; e = edge[e.next]) {
      if (e.to != to) {
        if (l_cnt == 0)
          left_one = get_a_child(e.to, from);
        else if (l_cnt == 1)
          left_two = get_a_child(e.to, from);
        l_cnt++;
      }
      if (l_cnt == 2) break;
    }
  }
  if (cnt[to] >= 3) {
    int r_cnt = 0;
    for (EDGE e = edge[head[to]]; e.next != -1; e = edge[e.next]) {
      if (e.to != from) {
        if (r_cnt == 0)
          right_one = get_a_child(e.to, to);
        else if (r_cnt == 1)
          right_two = get_a_child(e.to, to);
        r_cnt++;
      }
      if (r_cnt == 2) break;
    }
  }
  if (cnt[from] >= 3 && cnt[to] >= 3) {
    if (flag != -1) {
      cout << left_one << " " << right_one << " " << val / 2 << endl;
      cout << left_two << " " << right_two << " " << val / 2 << endl;
      cout << left_one << " " << left_two << " " << -val / 2 << endl;
      cout << right_one << " " << right_two << " " << -val / 2 << endl;
    }
    ans += 4;
  } else if (cnt[from] >= 3 && cnt[to] == 1) {
    if (flag != -1) {
      cout << left_one << " " << to << " " << val / 2 << endl;
      cout << left_two << " " << to << " " << val / 2 << endl;
      cout << left_one << " " << left_two << " " << -val / 2 << endl;
    }
    ans += 3;
  } else if (cnt[from] == 1 && cnt[to] >= 3) {
    if (flag != -1) {
      cout << right_one << " " << from << " " << val / 2 << endl;
      cout << right_two << " " << from << " " << val / 2 << endl;
      cout << right_one << " " << right_two << " " << -val / 2 << endl;
    }
    ans += 3;
  } else {
    if (flag != -1) cout << from << " " << to << " " << val << endl;
    ans += 1;
  }
}
int main() {
  edge[0].next = -1;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> f[i] >> t[i] >> v[i];
    cnt[f[i]]++;
    cnt[t[i]]++;
    add_edge(f[i], t[i], v[i]);
    add_edge(t[i], f[i], v[i]);
  }
  for (int i = 1; i <= n; i++)
    if (cnt[i] != 0 && cnt[i] == 2) {
      cout << "NO";
      return 0;
    }
  cout << "YES\n";
  for (int i = 0; i < n - 1; i++) handle(f[i], t[i], v[i], -1);
  cout << ans << endl;
  for (int i = 0; i < n - 1; i++) handle(f[i], t[i], v[i], 1);
}
