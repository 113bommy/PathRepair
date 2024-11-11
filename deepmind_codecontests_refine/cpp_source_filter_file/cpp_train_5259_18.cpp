#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
int a[100005];
int pos[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }
  int mx = 1;
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    if (pos[i] > pos[i - 1])
      cnt++;
    else
      cnt = 1;
    mx = max(mx, cnt);
  }
  cout << n - mx;
  return 0;
}
