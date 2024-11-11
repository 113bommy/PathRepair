#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
bool isp[1123456];
void getprime() {
  memset(isp, 1, sizeof(isp));
  isp[0] = isp[1] = 0;
  for (int i = 2; i < 1123456; i++) {
    if (!isp[i]) continue;
    for (int j = i + i; j < 1123456; j += i) {
      isp[j] = 0;
    }
  }
}
int n;
int a[1123456];
int vis[1123456];
long long sum[1123456];
vector<long long> vec;
int main() {
  getprime();
  int ans = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vis[a[i]] += 1;
    if (a[i] != 1) ans = max(ans, vis[a[i]]);
  }
  int tt = sqrt(1e5);
  for (int i = 2; i <= 1e5; i++) {
    int tem = 0;
    for (int j = i; j <= 1e5; j += i) {
      tem += vis[j];
    }
    ans = max(ans, tem);
  }
  cout << ans << '\n';
  return 0;
}
