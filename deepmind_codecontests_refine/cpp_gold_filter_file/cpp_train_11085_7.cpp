#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const long long inf = 1ll << 60;
char grid[maxn][maxn];
int ps[maxn][2];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> ap(3);
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    ap[in - 1]++;
  }
  cout << n - *max_element(ap.begin(), ap.end()) << '\n';
}
