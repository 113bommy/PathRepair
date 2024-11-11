#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
int main() {
  string st = "abcdefghijklmnopqrstuvwxyz";
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    long long int n, a, b;
    long long int vis[27];
    memset(vis, 0, sizeof(vis));
    cin >> n >> a >> b;
    vector<char> v;
    long long int temp = b, l = 0;
    while (temp--) {
      v.push_back(st[l]);
      vis[l] = 1;
      ++l;
    }
    long long int rem = a - b;
    for (int i = 0; i <= rem - 1; i++) {
      if (vis[i % 26] == 1) v.push_back(st[i % 26]);
    }
    long long int sz = v.size();
    for (int i = 0; i < n; i++) cout << v[i % sz];
    cout << "\n";
  }
}
