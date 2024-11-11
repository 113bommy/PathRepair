#include <bits/stdc++.h>
using namespace std;
int a[3][6], n, cnt[3][11];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) cin >> a[i][j], cnt[i][a[i][j]]++;
  }
  for (int i = 0; i <= 999; i++) {
    if (i < 10) {
      if (cnt[0][i])
        continue;
      else if (n > 1 && cnt[1][i])
        continue;
      else if (n > 2 && cnt[2][i])
        continue;
      else {
        if (!i)
          return cout << 0, 0;
        else
          return cout << i - 1, 0;
      }
    } else if (i >= 10 && i < 100) {
      if (n > 1 && cnt[0][i % 10] && cnt[1][i / 10])
        continue;
      else if (n > 1 && cnt[1][i % 10] && cnt[0][i / 10])
        continue;
      else if (n > 2 && cnt[0][i % 10] && cnt[2][i / 10])
        continue;
      else if (n > 2 && cnt[0][i / 10] && cnt[2][i % 10])
        continue;
      else if (n > 2 && cnt[1][i % 10] && cnt[2][i / 10])
        continue;
      else if (n > 2 && cnt[2][i % 10] && cnt[1][i / 10])
        continue;
      else
        return cout << i - 1, 0;
    } else if (i >= 100) {
      if (n > 2 && cnt[0][i / 100] && cnt[1][(i / 10) % 10] && cnt[2][i % 10])
        continue;
      else if (n > 2 && cnt[0][i / 100] && cnt[2][(i / 10) % 10] &&
               cnt[1][i % 10])
        continue;
      else if (n > 2 && cnt[1][i / 100] && cnt[0][(i / 10) % 10] &&
               cnt[2][i % 10])
        continue;
      else if (n > 2 && cnt[1][i / 100] && cnt[2][(i / 10) % 10] &&
               cnt[0][i % 10])
        continue;
      else if (n > 2 && cnt[2][i / 100] && cnt[0][(i / 10) % 10] &&
               cnt[1][i % 10])
        continue;
      else if (n > 2 && cnt[2][i / 100] && cnt[1][(i / 10) % 10] &&
               cnt[0][i % 10])
        continue;
      else
        return cout << i - 1, 0;
    }
  }
  return 0;
}
