#include <bits/stdc++.h>
using namespace std;
int b[+500500], a[+500500];
char c;
int n, i, j;
long long ans, cur;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(0);
  iostream::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> c;
    a[i] = (c == '1');
  }
  for (i = 1; i <= n; i++)
    if (a[i] == 0)
      ans += cur;
    else {
      int j = i;
      while (j < n && a[j + 1] == 1) j++;
      for (int x = 1; x <= (j - i + 1); x++) {
        cur += (i - 1 + x) - b[x];
        ans += cur;
        b[x] = (j - x + 1);
      }
      i = j;
    }
  cout << ans;
}
