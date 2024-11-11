#include <bits/stdc++.h>
using namespace std;
int T, n, q, ans;
pair<int, int> a[5005];
bool f[5005];
int calc(int i) {
  int x = min(a[i].second, (i == q - 1 ? 10000 : a[i + 1].first - 1)) -
          max((i == 0 ? 0 : a[i - 1].second + 1), a[i].first) + 1;
  return max(0, x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].first--;
    a[i].second--;
    for (int j = a[i].first; j <= a[i].second; j++) {
      f[j] = 1;
    }
  }
  int tmp = 0;
  for (int i = 0; i < n; i++)
    if (f[i]) tmp++;
  sort(a, a + q);
  for (int i = 0; i < q; i++) {
    int j = i;
    while (j < q && a[j].first == a[i].first) j++;
    reverse(a + i, a + j);
    i = j - 1;
  }
  int cnt = 0, id;
  for (int i = 0; i < q - 1; i++) {
    if (a[i].second >= a[i + 1].second) {
      cnt++;
      id = i + 1;
    }
  }
  if (cnt >= 2) {
    ans = tmp;
  } else if (cnt == 1) {
    for (int i = id; i < q - 1; i++) a[i] = a[i + 1];
    q--;
    for (int i = 0; i < q; i++) {
      int x = 0;
      x = calc(i);
      ans = max(ans, tmp - x);
    }
  } else {
    for (int i = 0; i < q - 1; i++) {
      for (int j = i + 2; j < q; j++) {
        int x = calc(i);
        int y = calc(j);
        ans = max(ans, tmp - x - y);
      }
      int x = min(a[i + 1].second, (i == q - 2 ? 10000 : a[i + 2].first - 1)) -
              max((i == 0 ? 0 : a[i - 1].second + 1), a[i].first) + 1;
      ans = max(ans, tmp - max(0, x));
    }
  }
  cout << ans << '\n';
  return 0;
}
