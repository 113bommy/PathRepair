#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char str[N];
long long a[N];
long long dp[N];
long long sum[N];
map<long long, int> mp;
int main() {
  for (int i = 'a'; i <= 'z'; i++) cin >> a[i];
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  long long s = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[str[i]];
  for (int i = 'a'; i <= 'z'; i++) {
    mp.clear();
    int x = 0, y = 0;
    int flag = 0;
    for (int j = 1; j <= n; j++) {
      if (flag == 0) {
        if (str[j] != i)
          continue;
        else {
          flag = 1;
          mp[2 * a[str[j]]] = 1;
          y = a[str[j]];
          continue;
        }
      }
      x += a[str[j]];
      if (str[j] == i) {
        y += x;
        s += mp[y];
        mp[y + a[str[j]]]++;
        x = 0;
      }
    }
  }
  cout << s;
  return 0;
}
