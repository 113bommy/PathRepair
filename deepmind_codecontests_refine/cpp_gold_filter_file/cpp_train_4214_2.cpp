#include <bits/stdc++.h>
using namespace std;
int n, a[6];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (n == 0) {
    puts("YES");
    puts("1\n1\n3\n3");
    return 0;
  }
  if (n == 1) {
    puts("YES");
    cout << a[1] << endl << a[1] * 3 << endl << a[1] * 3;
    return 0;
  }
  if (n == 2) {
    sort(a + 1, a + 3);
    for (int i = 1; i <= 3; ++i)
      for (int j = i + 1; j <= 4; ++j) {
        int b[5], c[5];
        b[1] = 0;
        b[2] = 0;
        b[3] = 0;
        b[4] = 0;
        b[i] = a[1];
        b[j] = a[2];
        int k = 0;
        for (int t = 1; t <= 4; ++t)
          if (b[t] == 0) {
            k = t;
            break;
          }
        for (int t = 1; t <= 4; ++t) c[t] = b[t];
        for (int x = 1; x <= 1000000; ++x) {
          for (int t = 1; t <= 4; ++t) b[t] = c[t];
          b[k] = x;
          for (int t = 1; t <= 4; ++t)
            if (b[t] < b[t - 1] && b[t - 1] != 0) break;
          int sum = 0;
          if (b[1] && b[4]) sum = (b[4] - b[1]) * 4;
          if (b[2] && b[3]) sum = (b[2] + b[3]) * 2;
          int s = 0;
          for (int t = 1; t <= 4; ++t) s += b[t];
          if (sum - s <= 0) continue;
          for (int t = 1; t <= 4; ++t)
            if (b[t] == 0) b[t] = sum - s;
          if (b[1] + b[2] + b[3] + b[4] != 2 * b[2] + 2 * b[3]) continue;
          if (b[1] + b[2] + b[3] + b[4] != 4 * b[4] - 4 * b[1]) continue;
          if (2 * b[2] + 2 * b[3] != 4 * b[4] - 4 * b[1]) continue;
          bool stop = false;
          for (int t = 1; t <= 3; ++t)
            if (b[t] > b[t + 1]) stop = true;
          if (stop) continue;
          puts("YES");
          for (int t = 1; t <= 4; ++t)
            if (c[t] == 0 || t == k) cout << b[t] << endl;
          return 0;
        }
      }
  }
  if (n == 3) {
    sort(a + 1, a + 4);
    for (int i = 1; i <= 2; ++i)
      for (int j = i + 1; j <= 3; ++j)
        for (int k = j + 1; k <= 4; ++k) {
          int b[5];
          b[1] = 0;
          b[2] = 0;
          b[3] = 0;
          b[4] = 0;
          b[i] = a[1];
          b[j] = a[2];
          b[k] = a[3];
          int sum = 0;
          if (b[1] && b[4]) sum = (b[4] - b[1]) * 4;
          if (b[2] && b[3]) sum = (b[2] + b[3]) * 2;
          int s = 0;
          for (int t = 1; t <= 4; ++t) s += b[t];
          if (sum - s <= 0) continue;
          for (int t = 1; t <= 4; ++t)
            if (b[t] == 0) b[t] = sum - s;
          if (b[1] + b[2] + b[3] + b[4] != 2 * b[2] + 2 * b[3]) continue;
          if (b[1] + b[2] + b[3] + b[4] != 4 * b[4] - 4 * b[1]) continue;
          if (2 * b[2] + 2 * b[3] != 4 * b[4] - 4 * b[1]) continue;
          bool stop = false;
          for (int t = 1; t <= 3; ++t)
            if (b[t] > b[t + 1]) stop = true;
          if (!stop) {
            puts("YES");
            for (int t = 1; t <= 4; ++t)
              if (t != i && t != j && t != k) cout << sum - s << endl;
            return 0;
          }
        }
  }
  if (n == 4) {
    sort(a + 1, a + 5);
    int b[6];
    b[1] = a[1];
    b[2] = a[2];
    b[3] = a[3];
    b[4] = a[4];
    b[5] = a[5];
    b[6] = a[6];
    if (b[1] + b[2] + b[3] + b[4] == 2 * b[2] + 2 * b[3])
      if (b[1] + b[2] + b[3] + b[4] == 4 * b[4] - 4 * b[1])
        if (2 * b[2] + 2 * b[3] == 4 * b[4] - 4 * b[1]) {
          puts("YES");
          return 0;
        }
  }
  cout << "NO";
}
