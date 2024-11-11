#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 5;
const int INF = 1e9;
const int M = 1000000007;
vector<int> adj[100005];
vector<int> vis(100005, 0);
void solve() { return; }
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ar[k];
    map<int, int> m1, m2;
    for (int i = 0; i < k; i++) {
      cin >> ar[i];
      m1[ar[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (m1[i] == 0) {
        ans++;
        if (i < n && m1[i + 1] == 0) {
          ans++;
        }
        if (i > 1 && m1[i - 1] == 0) {
          ans++;
        }
      }
    }
    for (int i = 0; i < k; i++) {
      int itr = ar[i];
      m2[itr]++;
      if (m2[itr] == 1) {
        if (itr < n && m1[itr + 1] == m2[itr + 1]) {
          ans++;
        }
        if (itr > 1 && m1[itr - 1] == m2[itr - 1]) {
          ans++;
        }
      }
      if (m1[itr] == m2[itr]) {
        if (itr < n && m1[itr + 1] == 0) {
          ans++;
        }
        if (itr > 1 && m1[itr - 1] == 0) {
          ans++;
        }
      }
    }
    cout << ans;
  }
  return 0;
}
