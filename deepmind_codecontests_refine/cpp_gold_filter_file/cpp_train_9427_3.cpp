#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string s;
  cin >> s;
  int a1 = 0;
  int a2 = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].size() < s.size())
      a1++;
    else if (arr[i].size() == s.size())
      a2++;
  }
  int ans = a1 + 5 * (a1 / k) + 1;
  int ans1 = 0;
  ans1 = (a1 + a2 - 1) + 5 * ((a1 + a2 - 1) / k) + 1;
  cout << ans << " " << ans1 << endl;
}
