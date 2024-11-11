#include <bits/stdc++.h>
using namespace std;
bool mark[1000001];
int p[1000001];
int find(int v) {
  if (p[v] < 0)
    return v;
  else
    return find(p[v]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ans = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    p[i] = -1;
  }
  cout << "1 ";
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    mark[a] = true;
    if (a + 1 <= n && mark[a + 1]) {
      p[find(a + 1)] += p[a];
      p[a] = find(a + 1);
    }
    if (a - 1 >= 1 && mark[a - 1]) {
      p[find(a)] += p[a - 1];
      p[a - 1] = find(a);
    }
    ans = i + 1;
    if (mark[n]) ans += p[n];
    cout << ans << " ";
  }
  return 0;
}
