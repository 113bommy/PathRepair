#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100005;
int father[Maxn];
map<int, int> numberloc;
int Find(int x) {
  if (father[x] != x) {
    return father[x] = Find(father[x]);
  } else
    return father[x];
}
void Union(int x, int y) {
  int dx = Find(x);
  int dy = Find(y);
  if (dx != dy) father[dx] = dy;
  return;
}
void _init() {
  for (int i = 1; i < Maxn; i++) {
    father[i] = i;
  }
}
int B[Maxn];
int main() {
  _init();
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> B[i];
    numberloc[B[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (numberloc[a - B[i]] != 0) {
      Union(i, numberloc[a - B[i]]);
    } else {
      Union(i, n + 2);
    }
    if (numberloc[b - B[i]] != 0) {
      Union(i, numberloc[b - B[i]]);
    } else {
      Union(i, n + 1);
    }
  }
  if (Find(n + 1) != Find(n + 2)) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      if (Find(i) == Find(n + 1))
        cout << 0 << ' ';
      else
        cout << 1 << ' ';
    }
    cout << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
