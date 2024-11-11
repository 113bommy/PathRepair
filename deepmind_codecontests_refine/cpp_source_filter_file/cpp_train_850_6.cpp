#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
void BoostIO() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
}
int main() {
  BoostIO();
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = n * (n - 1) / 2;
  vector<int> blocks;
  int cur_block_size = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      cur_block_size++;
      continue;
    } else {
      blocks.push_back(cur_block_size);
      cur_block_size = 1;
    }
  }
  blocks.push_back(cur_block_size);
  for (int i = 1; i < blocks.size(); ++i) {
    int cur = blocks[i];
    int prev = blocks[i - 1];
    ans -= cur + prev;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
