#include <bits/stdc++.h>
using namespace std;
struct Set {
  int head, tail, size;
  Set(int x) {
    head = tail = x;
    size = 1;
  }
  Set() { head = tail = size = 0; }
} s[100005];
int a[100005], Next[100005], head[100005];
void MakeSet(int x) {
  s[x] = Set(x);
  head[x] = x;
  Next[x] = -1;
}
int FindSet(int x) { return head[x]; }
void Union(int x, int y) {
  if (s[x].size == 0 || s[y].size == 0) return;
  if (s[x].size < s[y].size) swap(x, y);
  Next[s[x].tail] = s[y].head;
  s[x].tail = s[y].tail;
  s[x].size += s[y].size;
  head[s[y].tail] = s[x].head;
  for (int node = s[y].head; node != s[y].tail; node = Next[node])
    head[node] = s[x].head;
}
bool mark[100005];
pair<int, int> p[100005];
vector<int> v[100005];
int main() {
  long long n, m, x, y, sum = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    MakeSet(i);
    cin >> a[i];
    p[i] = make_pair(a[i], i);
  }
  sort(p, p + n);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v[x - 1].push_back(y - 1);
    v[y - 1].push_back(x - 1);
  }
  for (int i = n - 1; i >= 0; i--) {
    int x = p[i].second;
    mark[x] = true;
    for (int j = 0; j < v[x].size(); j++) {
      int y = v[x][j];
      int yn = FindSet(y), xn = FindSet(x);
      if (mark[y] && yn != xn) {
        sum += s[yn].size * s[xn].size * p[i].first;
        Union(xn, yn);
      }
    }
  }
  double ans = sum;
  ans /= double(n) * (n - 1) / 2;
  printf("%0.6f\n", ans);
  return 0;
}
