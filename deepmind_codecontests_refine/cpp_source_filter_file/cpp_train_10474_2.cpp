#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long base = 10000007;
long long large = 1000000000000000000LL;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > adj(n, vector<int>(1, 0));
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    int low = 0;
    int high = n - 1;
    int mid;
    int ans = n - 1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (adj[mid].back() >= x) {
        low = mid + 1;
      } else {
        ans = mid;
        high = mid - 1;
      }
    }
    adj[ans].push_back(x);
  }
  for (int i = 0; i < n - 1; i++) {
    if (adj[i].back() == 0) continue;
    for (int j = 1; j < (int)adj[i].size(); j++) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
