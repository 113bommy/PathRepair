#include <bits/stdc++.h>
using namespace std;
ifstream in("input.in");
ofstream out("output.out");
const long long nmx = 2e5 + 5;
const long long MOD = 1e9 + 7;
bool us[1000];
int main() {
  ios::sync_with_stdio(0);
  long long n, k, a[nmx];
  vector<int> ans[40];
  cin >> n >> k;
  for (long long i = 1; i <= k; ++i) {
    cin >> a[i];
    ans[i].push_back(a[i]);
    us[a[i]] = 1;
  }
  for (long long i = 1; i <= n * k; ++i)
    if (us[i] == 0) {
      long long mn = 1 << 30, wh = 0;
      for (long long j = 1; j <= k; ++j) {
        if (ans[j].size() < mn) {
          mn = ans[j].size();
          wh = j;
        }
      }
      ans[wh].push_back(i);
    }
  for (long long i = 1; i <= k; ++i) {
    for (auto k : ans[i]) cout << k << " ";
    cout << "\n";
  }
  return 0;
}
