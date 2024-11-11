#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int s[105], vis[105];
vector<int> vec;
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, m;
  while (cin >> n >> m) {
    vec.clear();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++) {
      cin >> s[i];
      vis[s[i]]++;
    }
    sort(vis, vis + 101, cmp);
    for (int i = 0; i < 101 && vis[i] != 0; i++) vec.push_back(vis[i]);
    int p = 1;
    while (1) {
      int ans = 0;
      for (int i = 0; i < vec.size(); i++) ans += vec[i] / p;
      if (ans < n) break;
      p++;
    }
    cout << p - 1 << endl;
  }
  return 0;
}
