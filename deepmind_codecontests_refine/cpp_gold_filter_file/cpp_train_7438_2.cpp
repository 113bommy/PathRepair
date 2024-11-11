#include <bits/stdc++.h>
using namespace std;
int n, r;
int ans = 0;
struct node {
  int x;
  int y;
  node(int a = 0, int b = 0) {
    x = a;
    y = b;
  }
  bool operator==(node &a) {
    if (x == a.x && y == a.y) return true;
    return false;
  }
};
vector<node> point;
node p[10];
node ansp[10];
node zero;
int size = 0;
int sqofdis(node &a, node &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
void dfs(int step, int pos, int num) {
  if (step >= n) {
    if (num > ans) {
      ans = num;
      for (int i = 0; i < n; i++) ansp[i] = p[i];
    }
    return;
  }
  for (int j = pos; j < size; j++) {
    int um = 0;
    p[step] = point[j];
    for (int k = 0; k < step; k++) um += sqofdis(p[step], p[k]);
    dfs(step + 1, j, num + um);
  }
  return;
}
bool cmp(const node &a, const node &b) {
  return a.x * a.x + a.y * a.y > b.x * b.x + b.y * b.y;
}
int main() {
  cin >> n >> r;
  for (int i = -r; i <= r; i++) {
    for (int j = -r; j <= r; j++) {
      node t(i, j);
      if (sqofdis(t, zero) <= r * r) point.push_back(t);
    }
  }
  sort(point.begin(), point.end(), cmp);
  size = (int)point.size() > 20 ? 20 : (int)point.size();
  dfs(0, 0, 0);
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << ansp[i].x << " " << ansp[i].y << endl;
  }
  return 0;
}
