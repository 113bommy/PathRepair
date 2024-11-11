#include <bits/stdc++.h>
using namespace std;
long long dir[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
string al = "abcdefghijklmnopqrstuvwxyz";
map<long long, long long> mp, mp2;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long i, j, n, ans = 0, cnt = 0, t, temp, p, k, mx = 0, x, y;
  cin >> n >> x >> y;
  long long a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (x > y) {
    cout << n;
    return 0;
  }
  sort(a, a + n);
  j = 0;
  for (i = n - 1; i >= 0; i--) {
    if (a[i] <= x) {
      j = i;
      break;
    }
  }
  i = 0;
  while (i < n) {
    if (a[i] > x && x <= y) break;
    i++;
    a[j] += y;
    if (a[j] > x) j--;
    cnt++;
  }
  cout << cnt;
}
