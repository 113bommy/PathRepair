#include <bits/stdc++.h>
using namespace std;
const string alf = "abcdefghijklmnopqrstuvwxyz";
const int hashP = 239017;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const int INF = 1e9;
const long long INF2 = 1e18;
template <typename T>
bool umn(T &a, T b) {
  return (a > b ? (a = b, 1) : 0);
}
template <typename T>
bool umx(T &a, T b) {
  return (a < b ? (a = b, 1) : 0);
}
int a[55][55];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  bool ok = 0;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == n - 1) {
        ans[i] = n;
        ok = 1;
        break;
      }
    }
    if (ok) break;
  }
  for (int i = 0; i < n; i++) {
    map<int, int> mapa;
    for (int j = 0; j < n; j++) {
      mapa[a[i][j]]++;
    }
    long long maxi = 0;
    for (auto now : mapa) umx(maxi, (long long)now.second);
    if (ans[i] == 0) ans[i] = n - maxi;
  }
  for (auto xxx : ans) cout << xxx << " ";
  cout << "\n";
  ;
  return 0;
}
