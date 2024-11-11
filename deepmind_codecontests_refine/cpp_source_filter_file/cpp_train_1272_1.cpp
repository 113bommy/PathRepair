#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, a[N];
int cnt[50];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 0; j <= 30; j++) {
      if (a[i] & (1 << j)) cnt[j]++;
    }
  }
  int ans = 0, ansp = 0;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 0; j <= 30; j++) {
      if (cnt[j] == 1 && (a[i] & (1 << j))) sum += 1 << j;
    }
    if (sum > ans) {
      ans = sum;
      ansp = i;
    }
  }
  cout << a[ansp] << ' ';
  for (int i = 1; i <= n; i++) {
    if (i == ansp) continue;
    cout << a[i] << ' ';
  }
  getchar();
  getchar();
  return 0;
}
