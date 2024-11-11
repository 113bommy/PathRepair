#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main() {
  int a, ans = 0;
  int A[100050];
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> a;
    vec.push_back(a);
  }
  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (j > n) break;
    if (vec[j] >= A[i]) {
      ans++;
      j++;
    }
  }
  cout << ans;
}
