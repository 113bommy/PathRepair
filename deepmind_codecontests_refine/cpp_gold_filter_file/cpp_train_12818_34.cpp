#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int n;
  int x;
  int y;
  int a[10000] = {};
  int b;
  int count = 0;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b = x - y;
  if (b > 0) {
    cout << n;
  }
  if (b <= 0) {
    for (int i = 0; i < n; i++) {
      if (x >= a[i]) {
        count += 1;
      }
    }
    if (count % 2 != 0) {
      count = count / 2 + 1;
    } else if (count % 2 == 0) {
      count = count / 2;
    }
    cout << count;
  }
  return 0;
}
