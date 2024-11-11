#include <bits/stdc++.h>
using namespace std;
int a[1000];
int auction[1000];
int normal[1000];
bool bo[1000];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(bo, false, sizeof(bo));
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    bo[tmp] = true;
    auction[i] = a[tmp];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (bo[i] == false) ans += a[i];
  for (int i = 0; i < m - 1; i++)
    for (int j = i + 1; j < m; j++)
      if (auction[j] < auction[i]) {
        int tmp = auction[i];
        auction[i] = auction[j];
        auction[j] = tmp;
      }
  for (int i = m - 1; i >= 0; i--)
    if (auction[i] <= ans)
      ans += ans;
    else
      ans += auction[i];
  cout << ans << endl;
}
