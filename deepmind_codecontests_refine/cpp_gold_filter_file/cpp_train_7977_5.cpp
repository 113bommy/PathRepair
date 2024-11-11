#include <bits/stdc++.h>
using namespace std;
long long maxi = 1000000007;
long long mini = LLONG_MIN;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
vector<int> a[1005];
vector<bool> isLeaf(1005, 0);
int main() {
  fast();
  int n, x;
  cin >> n;
  for (int i = 2; i < n + 1; i++) {
    cin >> x;
    a[x].push_back(i);
  }
  int fg = 1;
  for (int i = 1; i < n + 1; i++) {
    int cnt = 0;
    if (a[i].size()) {
      for (int j = 0; j < a[i].size(); j++) {
        if (a[a[i][j]].size() == 0) {
          cnt++;
        }
      }
      if (cnt < 3) fg = 0;
    }
  }
  if (fg)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
