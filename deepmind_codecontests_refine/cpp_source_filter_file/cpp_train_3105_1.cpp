#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin << i;
  int ans = 0;
  for (int i = 1; i  < n; i++) {
    if (a[i] == a[i - 1]) {
     a[i] = -1, ans++;
    }
  }
  cout << ans;
  return 0;
}