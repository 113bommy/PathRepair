#include <bits/stdc++.h>
using namespace std;
map<int, set<int> > mp;
std::vector<int> depth;
void dfs(int x, int d) {
  depth[d] ^= 1;
  for (int y : mp[x]) dfs(y, d + 1);
}
int main() {
  int n;
  cin >> n;
  depth = std::vector<int>(n + 1, 0);
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    mp[x - 1].insert(i + 1);
  }
  dfs(0, 0);
  int sum = 0;
  for (int k : depth) sum += k;
  cout << sum << endl;
}
