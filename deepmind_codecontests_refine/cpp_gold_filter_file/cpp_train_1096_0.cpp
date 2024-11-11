#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int INF = INT_MAX;
long long mini, maxi;
void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  mini = INF;
  maxi = INT_MIN;
  solve();
  return 0;
}
long long n, m;
long long mas[101];
void solve() {
  cin >> n;
  int index = 0, indexm = 0;
  for (int i = 0; i < n; ++i) {
    cin >> mas[i];
    if (mas[i] < mini) index = i;
    if (mas[i] > maxi) indexm = i;
    maxi = max(maxi, mas[i]);
    mini = min(mini, mas[i]);
  }
  if ((mini == mas[0] || mini == mas[n - 1]) &&
      (maxi == mas[0] || maxi == mas[n - 1])) {
    cout << n - 1;
    return;
  }
  int buf1 = max(index, indexm), buf2 = min(index, indexm);
  if (buf2 > n - buf1 - 1) {
    cout << buf1;
    return;
  } else {
    cout << n - buf2 - 1;
    return;
  }
}
