#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int d[maxn];
int main() {
  int cnt = 0, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    for (int j = 0; j < i; j++)
      if (d[j] > d[i]) cnt++;
  }
  int ans = cnt;
  if (cnt) cnt--;
  cout << cnt + ans << endl;
  return 0;
}
