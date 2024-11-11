#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e5;
const long long MAX = 1e18;
vector<int> arr[1000010];
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  long long ans = 1, temp = 1;
  for (int i = 0; i <= n - 1; ++i) {
    int g;
    cin >> g;
    while (g--) {
      int x;
      cin >> x;
      arr[x].push_back(i);
    }
  }
  sort(arr, arr + n);
  for (int i = 2; i <= m; ++i) {
    if (arr[i] == arr[i - 1]) {
      ++temp;
      ans *= temp;
      ans %= mod;
    } else
      temp = 1;
  }
  cout << ans << "\n";
  return 0;
}
