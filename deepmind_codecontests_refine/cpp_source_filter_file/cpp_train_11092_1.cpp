#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  long long n, arr[300000], x, l = 0, ans = 10000000000, flag = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (s[i] == 'R')
      l = arr[i];
    else {
      if (l) {
        flag = 1;
        if ((arr[i] - l) % 2 == 0)
          ans = min((arr[i] - l) / 2, ans);
        else
          ans = min((arr[i] - l) / 2 + 1, ans);
      }
    }
  }
  if (!flag)
    puts("-1");
  else
    cout << ans;
}
