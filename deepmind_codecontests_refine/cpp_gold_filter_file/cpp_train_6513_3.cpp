#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T maxer(T &a, T b) {
  a = max(a, b);
}
template <typename T>
inline T miner(T &a, T b) {
  a = min(a, b);
}
void inline iOS() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void inline fin() { freopen("in", "r", stdin); }
void inline fout() { freopen("out", "w", stdout); }
const int inf = ~0u / 10;
const long long linf = ~0ull / 20;
const int maxn = 1e5 + 20;
;
int n, a, b, k;
vector<int> ans;
string s;
int main() {
  iOS();
  cin >> n >> a >> b >> k >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') continue;
    int j = i;
    while (j < n && s[j] == '0') j++;
    j--;
    int dis = j - i + 1;
    if (dis < b) {
      i = j;
      continue;
    }
    for (int r = i + b - 1; r <= j; r += b) ans.push_back(r);
    i = j;
  }
  cout << ans.size() - a + 1 << '\n';
  for (int i = 0; i < ans.size() - a + 1; i++) cout << ans[i] + 1 << " ";
  return 0;
}
