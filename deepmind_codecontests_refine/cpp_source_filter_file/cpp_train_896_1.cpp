#include <bits/stdc++.h>
using namespace std;
struct item {
  int x, y;
};
int main() {
  int n, m;
  cin >> n >> m;
  item a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  if (n == 1) {
    if (a[0].x == 0 && a[0].y >= m) {
      cout << "YES";
      exit(0);
    } else {
      cout << "NO";
      exit(0);
    }
  }
  int last = a[0].y;
  for (int i = 1; i < n; i++) {
    if (a[i].x <= last)
      last = max(last, a[i].y);
    else
      break;
    if (a[i].y >= m) {
      cout << "YES";
      exit(0);
    }
  }
  cout << "NO";
}
