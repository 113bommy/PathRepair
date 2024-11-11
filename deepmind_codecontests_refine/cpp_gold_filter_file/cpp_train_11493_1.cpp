#include <bits/stdc++.h>
using namespace std;
const int N = 52;
const int INF = 0x3fffffff;
int setx[N], num[N];
bool vis[N];
int find(int x) {
  if (setx[x] == x) return x;
  return setx[x] = find(setx[x]);
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    setx[i] = i;
    num[i] = 1;
  }
  int a, b;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    int fx = find(a);
    int fy = find(b);
    if (fx != fy) {
      setx[fx] = fy;
      num[fy] += num[fx];
    }
  }
  for (int i = 1; i <= n; i++) {
    int fd = find(i);
    if (num[fd] > 3) {
      puts("-1");
      return 0;
    }
  }
  memset(vis, false, sizeof(vis));
  int c1 = 0, c2 = 0;
  vector<int> vec1;
  vec1.clear();
  for (int i = 1; i <= n; i++) {
    int fd = find(i);
    if (num[fd] == 2 && vis[fd] == false) {
      c2++;
      vis[fd] = true;
    }
    if (num[fd] == 1 && vis[fd] == false) {
      c1++;
      vis[fd] = true;
      vec1.push_back(i);
    }
  }
  if (c1 < c2) {
    puts("-1");
    return 0;
  }
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    int fd = find(i);
    if (num[fd] == 3 && vis[fd] == false) {
      printf("%d", i);
      for (int j = i + 1; j <= n; j++) {
        int fdd = find(j);
        if (fd == fdd) printf(" %d", j);
      }
      vis[fd] = true;
      puts("");
    }
  }
  int p = 0;
  for (int i = 1; i <= n; i++) {
    int fd = find(i);
    if (num[fd] == 2 && vis[fd] == false) {
      printf("%d", i);
      for (int j = i + 1; j <= n; j++) {
        int fdd = find(j);
        if (fd == fdd) printf(" %d", j);
      }
      vis[fd] = true;
      printf(" %d", vec1[p++]);
      puts("");
    }
  }
  while (p < vec1.size()) {
    printf("%d %d %d\n", vec1[p], vec1[p + 1], vec1[p + 2]);
    p += 3;
  }
  return 0;
}
