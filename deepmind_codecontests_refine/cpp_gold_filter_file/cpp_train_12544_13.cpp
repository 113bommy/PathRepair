#include <bits/stdc++.h>
using namespace std;
const int oo = 1000000000;
const int MAXN = 1010000 + 5;
const int rects = 1000;
pair<pair<int, int>, int> a[MAXN];
int n, x, y;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    int b = x / rects;
    if (b % 2 == 0) y *= -1;
    a[i] = pair<pair<int, int>, int>(pair<int, int>(b, y), i);
  }
  sort(a + 1, a + (n + 1));
  cout << a[1].second;
  for (int i = 2; i <= n; i++) {
    cout << " " << a[i].second;
  }
  cout << '\n';
}
