#include <bits/stdc++.h>
using namespace std;
long long a[1005], b[1005];
long long arr[1005];
int cnt;
bool judge(long long x) {
  for (int i = 0; i < cnt; i++)
    if (arr[i] == x) return false;
  return true;
}
void op(int x) {
  long long temp = arr[x];
  for (int i = x; i > 0; i--) {
    arr[i] = arr[i - 1];
  }
  arr[0] = temp;
}
int main() {
  long long n, m;
  while (cin >> n >> m) {
    cnt = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < m; i++) {
      if (judge(b[i])) {
        arr[cnt++] = b[i];
      }
      if (cnt == n) break;
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      long long temp = 0;
      for (int j = 0; j < cnt; j++) {
        if (arr[j] == b[i]) {
          ans += temp;
          op(j);
          break;
        } else {
          temp += arr[j];
        }
      }
    }
    cout << ans << endl;
  }
}
