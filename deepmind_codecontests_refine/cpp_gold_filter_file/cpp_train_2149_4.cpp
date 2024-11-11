#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      v[i].push_back(j - i);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      int last = v[i][j] + i;
      if (v[last].size() == 0)
        ans++;
      else {
        while (v[last].size() > 0) {
          int temp = v[last][v[last].size() - 1];
          v[last].pop_back();
          last += temp;
        }
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
