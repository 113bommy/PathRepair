#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  long long h;
  int n;
  cin >> h >> n;
  long long sum = 0;
  long long minn = 1e12;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    h += a[i];
    sum += a[i];
    if (sum < minn) {
      minn = sum;
    }
    if (h <= 0) {
      cout << i;
      return 0;
    }
  }
  long long cnt = n;
  long long t = -sum;
  if (sum >= 0) {
    cout << "-1";
  } else {
    if (h > -minn) {
      h = h + minn;
      cnt += (h / t) * n;
      h = h % t;
      h = h - minn;
    }
    while (h > 0) {
      for (int i = 1; i <= n; i++) {
        if (h <= 0) {
          cout << cnt;
          return 0;
        }
        cnt++;
        h += a[i];
      }
    }
  }
  return 0;
}
