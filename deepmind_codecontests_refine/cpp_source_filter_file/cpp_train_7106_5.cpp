#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<int> a(205);
vector<int> b(205);
bool isvalid(int x) {
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < m; j++) {
      int res = a[i] & b[j];
      if (res | x == x) {
        flag = true;
        break;
      }
    }
    if (flag == false) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int ans;
  for (int i = 0; i < (1 << 9); i++) {
    if (isvalid(i)) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
