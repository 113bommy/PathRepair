#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 69;
const int INF = 1e9 + 1;
int n, k, ip, mark[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) cin >> ip, mark[ip]++;
  }
  for (int i = 0; i <= 100; i++)
    if (mark[i] == n) cout << i << " ";
  cout << "\n";
}
