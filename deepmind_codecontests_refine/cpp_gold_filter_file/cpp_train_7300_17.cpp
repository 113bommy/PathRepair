#include <bits/stdc++.h>
using namespace std;
int N;
int a[1000];
void init() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> a[i];
}
void york() {
  int ans = -1;
  for (int i = 1; i < N; ++i)
    for (int j = i; j < N; ++j) {
      int w = a[i - 1] - 1;
      for (int k = i; k <= j; ++k) w %= a[k];
      int W = a[i - 1] - 1 - w + a[j];
      int s1 = 0;
      int s2 = 0;
      w = W;
      for (int k = i; k <= j; ++k) s1 += w / a[k], w %= a[k];
      w = W;
      for (int k = 0; k < N; ++k) s2 += w / a[k], w %= a[k];
      if (s2 > s1 && (ans == -1 || W < ans)) ans = W;
    }
  cout << ans << endl;
}
int main() {
  init();
  york();
  return 0;
}
