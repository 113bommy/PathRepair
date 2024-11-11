#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a[n];
  int ans = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    map<char, int> ma;
    for (int j = 0; j < n; j++) {
      ma[a[j][i]]++;
    }
    ans = ans * ma.size() % 1000000007;
  }
  cout << ans;
}
