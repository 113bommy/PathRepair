#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
vector<int> tree[1000000];
vector<int> tmp;
int rs[1000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  long long s = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  if (2 * n - 2 > s) {
    cout << "NO";
    return 0;
  }
  int re = 0;
  int last = 0, res = 0, t = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > 1) {
      rs[re++] = i;
      tree[last].push_back(i);
      --a[i];
      --a[last];
      last = i;
    } else if (a[i] == 1) {
      tmp.push_back(i);
      a[i] = 0;
      t++;
    }
  }
  if (!tmp.empty()) {
    int x = tmp.back();
    tmp.pop_back();
    tree[rs[0]].push_back(x);
  }
  cout << "YES " << (n - t) - 1 + min(t, 2) << "\n" << n - 1 << "\n";
  while (!tmp.empty()) {
    int x = tmp.back();
    tmp.pop_back();
    cout << x << " ";
    for (int i = n; i > 0; --i)
      if (a[i] != 0) {
        cout << i << "\n";
        a[i]--;
        break;
      }
  }
  for (int i = 0; i < re; ++i) {
    for (int x : tree[rs[i]]) {
      cout << rs[i] << " " << x << "\n";
    }
  }
  return 0;
}
