#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 17;
int n, w, a[MAXN], b[MAXN];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> w;
  if (w <= 0) return cout << "No" << endl, 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  iota(b + 1, b + n + 1, 1);
  sort(b + 1, b + n + 1, [](int i, int j) { return a[i] > a[j]; });
  if (w < a[b[n]] && w == 1) return cout << "No" << endl, 0;
  if (w == 1) {
    cout << "Yes" << endl;
    cout << b[n];
    for (int i = 1; i < n; i++)
      for (int j = 1; j <= a[b[i]]; j++) cout << " " << b[i] << " " << b[i];
    cout << " " << b[n] << endl;
    return 0;
  }
  if (a[b[1]] > w) {
    if (n == 1) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    cout << b[2];
    for (int i = 3; i <= n; i++)
      for (int j = 1; j <= a[b[i]]; j++) cout << " " << b[i] << " " << b[i];
    while (a[b[1]] >= w) {
      cout << " " << b[1] << " " << b[1];
      a[b[1]]--;
    }
    cout << " " << b[2];
    cout << " " << b[1];
    for (int i = 1; i <= a[b[2]] - 1; i++) cout << " " << b[2] << " " << b[2];
    cout << " " << b[1];
    for (int i = 1; i <= a[b[1]] - 1; i++) cout << " " << b[1] << " " << b[1];
    cout << endl;
  } else if (a[b[1]] == w) {
    cout << "Yes" << endl;
    cout << b[1] << " ";
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= a[b[i]]; j++) cout << b[i] << " " << b[i] << " ";
    cout << b[1];
    for (int i = 1; i <= a[b[1]] - 1; i++) cout << " " << b[1] << " " << b[1];
    cout << endl;
  } else {
    int t = 1, now = 0, x = 1;
    while (t <= n && now < w) now += a[b[t]], t++;
    if (now < w) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    cout << b[t - 1];
    int tmp = 1;
    while (now > w) {
      cout << " " << b[tmp] << " " << b[tmp];
      now--;
      a[b[tmp]]--;
      if (!a[b[tmp]]) tmp++;
    }
    for (int i = t; i <= n; i++)
      for (int j = 1; j <= a[b[i]]; j++) cout << " " << b[i] << " " << b[i];
    cout << " " << b[t - 1];
    a[b[t - 1]]--;
    for (int i = tmp; i < t; i++)
      for (int j = 1; j <= a[b[i]]; j++) cout << " " << b[i] << " " << b[i];
  }
  return 0;
}
