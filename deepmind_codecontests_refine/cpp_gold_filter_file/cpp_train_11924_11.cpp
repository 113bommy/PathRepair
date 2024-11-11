#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int cnt[N], pi[N];
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  memset(cnt, 0, sizeof(cnt));
  memset(pi, 0, sizeof(pi));
  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i(0); i < n; i++) {
    int a;
    cin >> a;
    if (a <= m) cnt[a]++;
    arr[i] = a;
  }
  for (int i(1); i <= m; i++) {
    for (int j(i); j <= m; j += i) {
      pi[j] += cnt[i];
    }
  }
  int ansv = -1, ansl = -1;
  for (int i(1); i <= m; i++) {
    if (ansv < pi[i]) {
      ansv = pi[i];
      ansl = i;
    }
  }
  cout << ansl << ' ' << ansv << '\n';
  for (int i(0); i < n; i++) {
    if (ansl % arr[i] == 0) {
      cout << i + 1 << ' ';
    }
  }
  return 0;
}
