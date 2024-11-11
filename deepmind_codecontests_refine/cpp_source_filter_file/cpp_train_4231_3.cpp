#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &i : arr) cin >> i;
  set<int> ss;
  int ans = 0;
  for (int i : arr) {
    if (ss.find(i) != ss.end()) ans++;
    ss.insert(i);
  }
  cout << ans;
  return 0;
}
