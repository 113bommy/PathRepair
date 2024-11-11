#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<bool> ans(n);
    ans[n - 1] = true;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] == 1)
        ans[i] = !ans[i + 1];
      else
        ans[i] = true;
    }
    if (ans[0])
      cout << "First\n";
    else
      cout << "Second\n";
  }
}
