#include <bits/stdc++.h>
using namespace std;
int n, ans, arr[200001], m, mx;
map<int, int> ma;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  arr[1] = 1;
  ma[1]++;
  for (int i = 2; i <= n; i++) {
    cin >> m;
    arr[i] = arr[m] + 1;
    ma[arr[i]]++;
    mx = max(arr[i], mx);
  }
  for (int i = 1; i <= mx; i++) {
    ans += (ma[arr[i]] % 2);
  }
  cout << ans;
}
