#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> dates(n), nor(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> dates[i];
    sum += dates[i];
    nor[i] = dates[i];
  }
  sort(dates.begin(), dates.end());
  if (sum % n == 0) {
    int media = sum / n;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (dates[i] == media) {
        ans.push_back(i + 1);
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    return 0;
  }
  cout << 0 << endl;
}
