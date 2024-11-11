#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = (int)2e5 + 10;
long long int h;
long long int n, mn = 0, tot = 0;
int d[MAX];
void monta() {
  cin >> h >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  for (int i = 0; i < n; i++) {
    tot += d[i];
    mn = min(mn, tot);
  }
}
void vai() {
  if (h < -mn) {
    for (int i = 0; i < n; i++) {
      h += d[i];
      if (h <= 0) {
        cout << i + 1 << endl;
        return;
      }
    }
    cout << "errei" << endl;
    return;
  }
  if (tot >= 0) {
    cout << -1 << endl;
    return;
  }
  long long int cu = h - mn;
  long long int q = (cu / -tot) - 2;
  h -= q * (-tot);
  if (h <= 0) {
    cout << n * q << endl;
    return;
  }
  long long int ret = (q * n) + 1;
  for (int i = 0; i <= 2 * n; i++, ret++) {
    h += d[i % n];
    if (h <= 0) {
      break;
    }
  }
  cout << ret << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  monta();
  vai();
  return 0;
}
