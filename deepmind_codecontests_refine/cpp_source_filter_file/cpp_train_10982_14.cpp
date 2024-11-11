#include <bits/stdc++.h>
using namespace std;
int n, cur, sieve[2020];
vector<int> ans;
bool siv[2020];
int main() {
  cin >> n;
  for (int x = 2; x <= n; x++) {
    if (sieve[x]) continue;
    for (int u = 2 * x; u <= n; u += x) {
      sieve[u] = x;
    }
  }
  int t = 0;
  for (int i = 2; i <= n; i++) {
    if (sieve[i]) continue;
    t++;
    ans.push_back(i);
    int j = i * i;
    while (j < n) {
      ans.push_back(j);
      t++;
      j *= i;
    }
  }
  cout << t << endl;
  int x = ans.size();
  for (int i = 0; i <= x - 1; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
