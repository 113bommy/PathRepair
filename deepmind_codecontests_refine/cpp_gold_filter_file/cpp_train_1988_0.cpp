#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int N = 1e6 + 6;
const int logN = 17;
int n;
int get_diff(int x) {
  int a, b;
  cout << "? " << x << endl;
  fflush(stdout);
  cin >> a;
  cout << "? " << x + n / 2 << endl;
  fflush(stdout);
  cin >> b;
  return b - a;
}
int main() {
  scanf("%d", &n);
  int t1 = get_diff(1);
  if (abs(t1) & 1) {
    cout << "! " << -1 << endl;
    fflush(stdout);
    return 0;
  }
  t1 = max(-1, t1);
  t1 = min(1, t1);
  if (t1 == 0) {
    cout << "! 1\n";
    fflush(stdout);
    return 0;
  }
  int bas = 1, son = n / 2;
  while (bas < son) {
    int mid = (bas + son) / 2;
    int t = get_diff(mid);
    t = min(1, t);
    t = max(-1, t);
    if (t == 0) {
      cout << "! " << mid << endl;
      fflush(stdout);
      return 0;
    }
    if (t == t1) {
      bas = mid + 1;
    } else
      son = mid - 1;
  }
  cout << "! " << bas << endl;
  fflush(stdout);
  return 0;
  return 0;
}
