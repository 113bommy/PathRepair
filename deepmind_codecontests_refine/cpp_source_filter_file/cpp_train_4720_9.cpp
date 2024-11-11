#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
vector<int> vec;
int arr[10000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  for (int i = 0; i < 10000005; ++i) arr[i] = inf;
  for (int i = 1; i * i <= 10000000; ++i) {
    vec.push_back(i * i);
  }
  int a, n;
  cin >> a >> n;
  for (int i = 0; i < vec.size() && vec[i] <= a + n - 1; ++i) {
    for (int j = (a + vec[i] - 1) / vec[i]; j * vec[i] <= a + n - 1; ++j) {
      arr[j * vec[i]] = min(arr[j * vec[i]], j);
    }
  }
  int ans = 0;
  for (int i = a; i <= a + n - 1; ++i) {
    ans += arr[i];
  }
  cout << ans << '\n';
}
