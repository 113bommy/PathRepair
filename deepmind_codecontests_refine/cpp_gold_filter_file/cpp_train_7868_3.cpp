#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
map<long long, int> Map;
map<long long, int> Map2;
int a[maxn];
long long sum[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    Map[a[i]]++;
  }
  long long cnt;
  int i;
  for (i = 0; i <= n; i++) {
    cnt = sum[n] - sum[i] - sum[i];
    if (cnt < 0) break;
    if (cnt & 1) continue;
    cnt >>= 1;
    Map[a[i]]--;
    Map2[a[i]]++;
    if (Map[cnt] || cnt == 0) {
      printf("YES\n");
      return 0;
    }
  }
  for (i; i <= n; i++) {
    cnt = sum[i] - (sum[n] - sum[i]);
    if (cnt & 1) continue;
    cnt >>= 1;
    if (Map2[cnt]) {
      printf("YES\n");
      return 0;
    }
    Map2[a[i]]++;
  }
  printf("NO\n");
}
