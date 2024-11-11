#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
struct Node {
  int l, r;
  Node() {}
  Node(int _l, int _r) : l(_l), r(_r) {}
  bool operator<(const Node n) const { return l != n.l ? l < n.l : r < n.r; }
};
vector<Node> a[100005], b[100005];
int use[100005];
int n, m, k, cnt = 0;
map<int, int> row, col;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      if (y1 > y2) swap(y1, y2);
      if (col.find(x1) == col.end()) {
        col[x1] = cnt++;
        a[cnt - 1].push_back(Node(y1, y2));
      } else {
        a[col[x1]].push_back(Node(y1, y2));
      }
    } else {
      if (x1 > x2) swap(x1, x2);
      if (row.find(y1) == row.end()) {
        row[y1] = cnt++;
        a[cnt - 1].push_back(Node(x1, x2));
      } else {
        a[row[y1]].push_back(Node(x1, x2));
      }
    }
  }
  for (int i = 0; i < cnt; i++) {
    sort(a[i].begin(), a[i].end());
    int l = a[i][0].l, r = a[i][0].r;
    for (int j = 1; j < a[i].size(); j++) {
      if (a[i][j].l > r) {
        b[i].push_back(Node(l, r));
        use[i] += r - l;
        l = a[i][j].l;
        r = a[i][j].r;
      } else {
        r = max(r, a[i][j].r);
      }
    }
    use[i] += r - l;
    b[i].push_back(Node(l, r));
  }
  int ans = 0;
  int r = m - 1 - row.size(), c = n - 1 - col.size();
  if (r & 1) ans ^= n;
  if (c & 1) ans ^= m;
  for (map<int, int>::iterator it = row.begin(); it != row.end(); it++) {
    int remain = n - use[it->second];
    ans ^= remain;
  }
  for (map<int, int>::iterator it = col.begin(); it != col.end(); it++) {
    int remain = m - use[it->second];
    ans ^= remain;
  }
  if (ans == 0)
    puts("SECOND");
  else {
    puts("FIRST");
    for (int i = 1; i < n; i++) {
      int remain;
      if (col.find(i) == col.end()) {
        remain = m;
        if (remain >= (remain ^ ans)) {
          int t = remain - (remain ^ ans);
          printf("%d %d %d %d\n", i, 0, i, t);
          return 0;
        } else
          break;
      }
    }
    for (int i = 1; i < m; i++) {
      int remain;
      if (row.find(i) == row.end()) {
        remain = n;
        if (remain >= (remain ^ ans)) {
          int t = remain - (remain ^ ans);
          printf("%d %d %d %d\n", 0, i, t, i);
          return 0;
        } else
          break;
      }
    }
    for (map<int, int>::iterator it = row.begin(); it != row.end(); it++) {
      int i = it->second, remain = m - use[i];
      if (remain >= (remain ^ ans)) {
        int t = remain - (remain ^ ans);
        int sum = 0, pre = 0;
        b[i].push_back(Node(m, m));
        for (int j = 0; j < b[i].size(); j++) {
          if (sum + b[i][j].l - pre >= t) {
            printf("%d %d %d %d\n", 0, it->first, pre + t - sum, it->first);
            break;
          }
          sum += b[i][j].l - pre;
          pre = b[i][j].r;
        }
        return 0;
      }
    }
    for (map<int, int>::iterator it = col.begin(); it != col.end(); it++) {
      int i = it->second, remain = n - use[i];
      if (remain >= (remain ^ ans)) {
        int t = remain - (remain ^ ans);
        int sum = 0, pre = 0;
        b[i].push_back(Node(n, n));
        for (int j = 0; j < b[i].size(); j++) {
          if (sum + b[i][j].l - pre >= t) {
            printf("%d %d %d %d\n", it->first, 0, it->first, pre + t - sum);
            break;
          }
          sum += b[i][j].l - pre;
          pre = b[i][j].r;
        }
        return 0;
      }
    }
  }
  return 0;
}
