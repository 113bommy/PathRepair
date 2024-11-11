#include <bits/stdc++.h>
using namespace std;
bool file = 0, rt = 1;
clock_t tStart;
void FAST_IO();
int a[102];
int main() {
  FAST_IO();
  cout << setprecision(5);
  cout << fixed;
  int n, x, y;
  cin >> n >> x >> y;
  int l = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < x) {
      l++;
    }
  }
  if (x > y) {
    cout << n << '\n';
    return 0;
  }
  if (l % 2 == 0) {
    cout << l / 2 << '\n';
    return 0;
  } else {
    if (l > 2)
      cout << (l + 1) / 2 << '\n';
    else
      cout << 1 << '\n';
    return 0;
  }
  return 0;
}
void FAST_IO() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  if (rt && file) {
    tStart = clock();
  }
  if (file) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
}
