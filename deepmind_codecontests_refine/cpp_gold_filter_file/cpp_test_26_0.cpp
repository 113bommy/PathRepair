#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
bool check(vector<int> vec) {
  int cnt = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] > 0) cnt++;
    if (cnt > 2) return false;
  }
  return true;
}
long long MAX = 1e9 + 7;
void sol() {
  int n;
  cin >> n;
  long long cnt = 1;
  long long mod = MAX;
  for (int i = 2 * n; i >= 3; i--) {
    cnt = (cnt * i) % mod;
    ;
  }
  cnt = cnt % mod;
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
}
