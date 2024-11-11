#include <bits/stdc++.h>
using namespace std;
int n, temp, arr[2000 + 5][2000 + 5];
long long rl[2 * 2000 + 5], lr[2 * 2000 + 5];
pair<long long, pair<int, int> > xaml[4], xamr[4];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
      rl[i + j] += arr[i][j];
      lr[n + i - j - 1] += arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2) {
        if (xaml[1].first <= rl[i + j] + lr[n + i - j - 1] - arr[i][j]) {
          xaml[1].first = rl[i + j] + lr[n + i - j - 1] - arr[i][j];
          xaml[1].second = make_pair(i + 1, j + 1);
          if (xaml[0].first <= xaml[1].first) swap(xaml[0], xaml[1]);
        }
      } else {
        if (xamr[1].first <= rl[i + j] + lr[n + i - j - 1] - arr[i][j]) {
          xamr[1].first = rl[i + j] + lr[n + i - j - 1] - arr[i][j];
          xamr[1].second = make_pair(i + 1, j + 1);
          if (xamr[0].first <= xamr[1].first) swap(xamr[0], xamr[1]);
        }
      }
    }
  }
  printf("%lld\n", xamr[0].first + xaml[0].first);
  printf("%d %d %d %d\n", xamr[0].second.first, xamr[0].second.second,
         xaml[0].second.first, xaml[0].second.second);
}
