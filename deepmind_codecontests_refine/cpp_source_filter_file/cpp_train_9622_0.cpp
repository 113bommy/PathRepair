#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int mx = 0;
  int ans[105];
  for (int i = 1; i <= n; i++) {
    vector<int> in;
    if (a[i] > 0) {
      in.push_back(i);
      for (int j = i + 1; j <= n; j++) {
        if (a[j] == a[in[in.size() - 1]] + 1) {
          in.push_back(j);
        }
      }
      if (in.size() > mx) {
        mx = in.size();
        for (int j = 1; j <= in.size(); j++) {
          ans[j] = in[j - 1];
        }
      }
    }
  }
  cout << mx << endl;
  for (int i = 1; i <= mx; i++) {
    cout << (2000 + ans[i]) << " ";
  }
  cout << endl;
}
