#include <bits/stdc++.h>
using namespace std;
void Code_Bela_Hadaf_() {}
const double PI = 22.0 / 7;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int MOD = 1e9 + 7;
const int INF = 1e9 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Code_Bela_Hadaf_();
  int t;
  cin >> t;
  while (t--) {
    string second;
    int n;
    cin >> n;
    cin >> second;
    int ans = 0;
    reverse(second.begin(), second.end());
    if (second[0] != '1') {
      ans += (second[0] - '0');
    }
    for (int i = 1; i < n; i++) {
      if (second[i] != '0') {
        ans += (second[i] - '0') + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
