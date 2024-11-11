#include <bits/stdc++.h>
using namespace std;
string s;
int n, ans;
bool d[1001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    if (d[i] == 1) ans++;
  }
  if (ans) ans += ans - 1;
  for (int i = 0; i < n - 1; i++) {
    if (d[i] == 1 && d[i + 1] == 1) ans--;
  }
  cout << ans << endl;
  return 0;
}
