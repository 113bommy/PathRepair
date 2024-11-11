#include <bits/stdc++.h>
using namespace std;
long long binexp(long long a, long long b, long long m) {
  a = a % m;
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
int arr[1005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    arr[x]++;
    int j;
    for (j = 1; j <= n; j++) {
      if (arr[j] == 0) break;
    }
    if (j == n + 1) {
      cnt++;
      for (j = 1; j <= n; j++) arr[j]--;
    }
  }
  cout << cnt << "\n";
  return 0;
}
