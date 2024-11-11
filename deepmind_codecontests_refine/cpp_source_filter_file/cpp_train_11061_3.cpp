#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
void solve() {
  long long int n, a;
  cin >> n;
  vector<long long int> v1(n + 2), v2(n + 2);
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    v1[a] = i + 1;
  }
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    v2[a] = i + 1;
  }
  vector<long long int> ans(n + 2, 0);
  long long int val;
  for (long long int i = 1; i <= n; i++) {
    long long int val1 = v1[i];
    long long int val2 = v2[i];
    if (val2 <= val1) {
      val = val1 - val2;
    } else {
      val = n - val2;
      val += val1;
    }
    ans[val]++;
  }
  long long int fin = 0;
  for (long long int i = 1; i <= n; i++) {
    fin = max(fin, ans[i]);
  }
  cout << fin << endl;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
