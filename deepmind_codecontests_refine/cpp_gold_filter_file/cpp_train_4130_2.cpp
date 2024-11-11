#include <bits/stdc++.h>
using namespace std;
bool chk[1002];
vector<int> v;
int a[1002], b[1002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, num;
  cin >> n;
  int k = 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i >= 1; i--) {
    if (!chk[a[i]]) {
      chk[a[i]] = 1;
      b[k++] = a[i];
    }
  }
  k--;
  cout << k << "\n";
  for (int i = k; i >= 1; i--) cout << b[i] << " ";
}
