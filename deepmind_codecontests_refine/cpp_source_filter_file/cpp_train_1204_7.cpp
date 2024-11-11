#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int cnt[N], vis[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  int res = 0;
  for (int i = 2; i < N; i++)
    if (!vis[i]) {
      int tmp = 0;
      for (int j = i; j < N; j += i) {
        tmp += cnt[j];
        vis[j] = 1;
      }
      res = max(res, tmp);
    }
  cout << res << endl;
  return 0;
}
