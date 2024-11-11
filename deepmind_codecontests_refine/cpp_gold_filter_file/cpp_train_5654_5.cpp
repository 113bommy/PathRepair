#include <bits/stdc++.h>
using namespace std;
long long int p = 31;
long long int m = 1000000009;
int main() {
  long long int n, a, b;
  cin >> n >> a >> b;
  long long int x = a, y = b;
  vector<long long int> ans;
  long long int s;
  if (b > 0) {
    ans.push_back(1);
    ans.push_back(2);
    b--;
    s = 3;
  } else {
    ans.push_back(1);
    ans.push_back(1);
    s = 2;
    if (a == 0) {
      for (long long int i = 1; i <= n; i++) {
        cout << 1 << " ";
      }
      return 0;
    }
  }
  while (b > 0 && ans.size() < n) {
    ans.push_back(s + 1);
    s = s + ans[ans.size() - 1];
    b--;
  }
  while (a > 0 && ans.size() < n) {
    ans.push_back(ans[ans.size() - 1] + 1);
    s = s + ans[ans.size() - 1] + 1;
    a--;
  }
  long long int l = ans.size();
  long long int d = n - l;
  while (d > 0 && ans.size() < n) {
    ans.push_back(ans[ans.size() - 1]);
    d--;
  }
  long long int hi = 0;
  long long int wow = 0;
  long long int sum = ans[0];
  long long int maxi = ans[0];
  for (long long int i = 1; i < ans.size(); i++) {
    if (ans[i] > sum) {
      wow++;
      maxi = ans[i];
    } else if (ans[i] > maxi) {
      hi++;
      maxi = ans[i];
    }
    sum = sum + ans[i];
  }
  if (hi != x || wow != y) {
    cout << -1;
    return 0;
  }
  for (long long int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
