#include <bits/stdc++.h>
using namespace std;
long long int sumdigit(long long int num) {
  long long int sum = 0;
  while (num) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    int dp1[1002] = {0}, dp2[1002] = {0};
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      dp1[a[i]]++;
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
      dp2[b[i]]++;
    }
    bool ans = false;
    int value;
    for (int i = 0; i < 1002; i++) {
      if (dp1[i] > 0 && dp2[i] > 0) {
        ans = true;
        value = i;
        break;
      }
    }
    if (ans) {
      cout << "YES" << endl;
      cout << 1 << " " << value << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
