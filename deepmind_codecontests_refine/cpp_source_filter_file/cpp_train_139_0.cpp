#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> home(101, 0);
  vector<int> away(n);
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    home[x]++;
    cin >> away[i];
  }
  long long sol;
  for (int i = 0; i < n; i++) {
    sol += home[away[i]];
  }
  cout << sol;
  return 0;
}
