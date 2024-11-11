#include <bits/stdc++.h>
using namespace std;
struct person {
  long long time;
  int from;
  int to;
  int id;
  void read() {
    cin >> time >> from >> to;
    from--;
    to--;
  }
  friend bool operator<(const person &a, const person &b) {
    return a.time < b.time;
  }
};
person a[100005];
int sum[300005];
long long ans[100005];
int id[100005];
int visit[100005];
inline int lowbit(int x) { return x & (-x); }
inline int query(int x) {
  x++;
  int tot = 0;
  for (; x != 0; x -= lowbit(x)) {
    tot += sum[x];
  }
  return tot;
}
inline int get_val(int x, int y) { return query(y) - query(x); }
void change_val(int x, int val) {
  x++;
  int j;
  for (j = x; j <= 100000; j += lowbit(j)) {
    sum[j] += val;
  }
}
int find_up(int up) {
  int l = up, r = 99999;
  int t = query(up - 1);
  for (; l <= r;) {
    int mid = (l + r) / 2;
    if (query(mid) - t == 0)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return r + 1;
}
int find_down(int up) {
  int l = 0, r = up;
  int t = query(up + 1);
  for (; l <= r;) {
    int mid = (l + r) / 2;
    if (t - query(mid) == 0)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return r + 1;
}
vector<int> v[100005];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int i;
  for (i = 0; i < n; i++) {
    a[i].read();
    a[i].id = i;
    visit[i] = 0;
  }
  for (i = 0; i < n; i++) {
    id[a[i].id] = i;
  }
  sort(a, a + n);
  int floor = 0;
  long long time = 0;
  a[n].time = 999999999999999999ll;
  memset(ans, -1, sizeof(ans));
  for (i = 0; i < n; i++) {
    time = a[i].time;
    change_val(a[i].from, 1);
    v[a[i].from].push_back(i);
    for (;;) {
      int up = get_val(floor, m);
      int down = get_val(-1, floor);
      visit[i] = 1;
      if ((up == 0) && (down == 0)) {
        break;
      }
      int t;
      if (up >= down) {
        t = find_up(floor);
        if (t - floor > a[i + 1].time - time) {
          floor += (a[i + 1].time - time);
          break;
        }
        time += (t - floor);
        floor = t;
      } else {
        t = find_down(floor);
        if (floor - t > a[i + 1].time - time) {
          floor -= (a[i + 1].time - time);
          break;
        }
        time += (floor - t);
        floor = t;
      }
      int j;
      for (j = 0; j < v[t].size(); j++) {
        if (visit[v[t][j]] == 1) {
          change_val(a[v[t][j]].to, 1);
          v[a[v[t][j]].to].push_back(v[t][j]);
          visit[v[t][j]] = 2;
        } else {
          ans[a[v[t][j]].id] = time;
          visit[v[t][j]] = 3;
        }
      }
      change_val(t, -v[t].size());
      v[t].resize(0);
    }
  }
  for (i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
