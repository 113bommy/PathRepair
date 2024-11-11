#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> xs;
    for (int i = 0; i < n; i++) {
      int in;
      cin >> in;
      xs.push_back(in);
    }
    sort(xs.begin(), xs.end());
    int answer = 0;
    vector<int> ans;
    ans.assign(110, 0);
    for (int i = 0; i < xs.size(); i++) {
      ans[xs[i]] = 1;
    }
    for (int i = 1; i < 110; i++) {
      if (!ans[i]) {
        if (!x) break;
        ans[i] = 1;
        x--;
        answer = max(answer, i);
      } else {
        answer = max(answer, i);
      }
    }
    cout << answer << endl;
  }
  return 0;
}
