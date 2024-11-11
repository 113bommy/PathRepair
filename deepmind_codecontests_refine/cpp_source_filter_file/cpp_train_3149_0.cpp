#include <bits/stdc++.h>
using namespace std;
vector<int> con[200000];
vector<int> conr[200000];
int cd[200000] = {0}, cu[200000] = {0};
int cold(int i) {
  if (cd[i] == -1) return 1;
  if (cd[i]) return 0;
  cd[i] = -1;
  for (auto x : con[i])
    if (cold(x)) return 1;
  cd[i] = 1;
  return 0;
}
int colu(int i) {
  if (cu[i] == -1) return 1;
  if (cu[i]) return 0;
  cu[i] = -1;
  for (auto x : conr[i])
    if (colu(x)) return 1;
  cu[i] = 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    con[a].push_back(b);
    conr[b].push_back(a);
  }
  int r = 0;
  vector<int> sol(n);
  for (int i = 0; i < n; i++) {
    if (!cd[i] && !cu[i]) {
      sol[i] = 1;
      r++;
    }
    if (cold(i) || colu(i)) {
      cout << 1 << '\n';
      return 0;
    }
  }
  cout << r << '\n';
  for (auto x : sol) {
    cout << (x ? "A" : "E");
  }
  cout << '\n';
}
