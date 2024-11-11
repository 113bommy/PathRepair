#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long n, c[N], ans[N], pw[64];
queue<int> q[64];
int main() {
  cin >> n;
  pw[0] = 1;
  for (int i = 1; i <= 60; i++) pw[i] = pw[i - 1] << 1;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    for (int j = 60; j >= 0; j--)
      if (c[i] & pw[j]) {
        q[j].push(c[i]);
        break;
      }
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    for (int j = 0; j <= 60; j++)
      if (!(sum & pw[j]) && !q[j].empty()) {
        ans[i] = q[j].front(), sum ^= q[j].front(), q[j].pop();
        flag = 1;
        break;
      }
    if (!flag) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
