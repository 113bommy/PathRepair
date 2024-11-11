#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());
int n, x, y, b[N], a[N], ans[N];
vector<int> v[N], col[N];
bool ok;
int main() {
  int T;
  cin >> T;
  while (T--) {
    ok = 0;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i <= n + 1; i++) {
      v[i].clear();
      col[i].clear();
    }
    int free;
    for (int i = 0; i < n; i++) {
      scanf("%d", b + i);
      col[b[i]].push_back(i);
    }
    for (int i = 1; i <= n + 1; i++)
      if (col[i].empty()) free = i;
    vector<int> temp;
    for (int i = 0; i <= n + 1; i++)
      if (col[i].size()) {
        v[col[i].size()].push_back(i);
        ans[i] = free;
      }
    int bad = n - y;
    y -= x;
    for (int i = n; x; i--) {
      while (x && v[i].size()) {
        int temp = v[i].back();
        v[i].pop_back();
        ans[col[temp].back()] = temp;
        col[temp].pop_back();
        if (col[temp].size()) v[i - 1].push_back(temp);
        x--;
      }
    }
    int mx = 0;
    for (int i = 0; i <= n; i++)
      while (v[i].size()) {
        mx = i;
        for (auto j : col[v[i].back()]) temp.push_back(j);
        v[i].pop_back();
      }
    for (int i = 0; i < temp.size(); i++)
      ans[temp[(i + mx) % temp.size()]] = b[temp[i]];
    for (int i = 0; i < temp.size() && bad; i++)
      if (ans[temp[i]] == b[temp[i]]) ans[temp[i]] = free, bad--;
    for (int i = 0; bad; i++)
      if (ans[temp[i]] != free) ans[temp[i]] = free, bad--;
    for (auto i : temp) ok |= ans[i] == b[i];
    if (ok) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    puts("");
  }
}
