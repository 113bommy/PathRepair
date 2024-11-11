#include <bits/stdc++.h>
using namespace std;
int N, w[100000], width;
pair<int, int> h[100000];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> h[i].first;
    h[i].second = i;
    width += w[i];
  }
  sort(h, h + N);
  for (int i = 0; i < N; i++) {
    int ans = width - w[i];
    if (h[N - 1].second == i)
      ans *= h[N - 2].first;
    else
      ans *= h[N - 1].first;
    cout << ans << " ";
  }
  return 0;
}
