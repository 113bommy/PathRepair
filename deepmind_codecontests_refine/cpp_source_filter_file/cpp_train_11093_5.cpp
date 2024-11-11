#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n;
int s[MAXN];
bool check(int k) {
  for (int i = 0; i < k; i++) {
    bool flag = true;
    for (int j = 0; j < n; j += k) {
      if (!s[j]) {
        flag = false;
        break;
      }
    }
    if (flag) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (n / i >= 3 && check(i)) {
        cout << "YES" << endl;
        return 0;
      }
      if (i * i != n && i >= 3 && check(n / i)) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
