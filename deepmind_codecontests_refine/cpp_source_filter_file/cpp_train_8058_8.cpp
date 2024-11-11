#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int ans[100000];
int n, m;
set<int> s;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    s.insert(arr[i]);
    ans[i] = s.size();
  }
  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;
    cout << ans[temp] << endl;
  }
  return 0;
}
