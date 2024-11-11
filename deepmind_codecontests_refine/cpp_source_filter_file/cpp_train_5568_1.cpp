#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int h[n], w[n];
  for (int i = 0; i < (int)(n); i++) cin >> h[i] >> w[i];
  int M = max(*max_element(w, w + n), *max_element(h, h + n));
  assert(M <= 1000 && n <= 1000);
  int ans = M * M * n;
  vector<int> diff;
  for (int H = 1; H <= M; H++) {
    diff.clear();
    int cnt = 0, bad = 0, sumW = 0;
    for (int i = 0; i < (int)(n); i++)
      if (h[i] > H && w[i] > H)
        bad = 1;
      else if (h[i] >= w[i])
        if (h[i] > H)
          sumW += h[i], cnt++;
        else
          sumW += w[i];
      else {
        sumW += w[i];
        if (w[i] <= H) diff.push_back(h[i] - w[i]);
      }
    sort((diff).begin(), (diff).end());
    if (cnt <= n / 2 && !bad)
      ans =
          min(ans, H * (sumW + accumulate(diff.begin(),
                                          diff.begin() + min((int)(diff).size(),
                                                             n / 2 - cnt),
                                          0)));
  }
  cout << ans << endl;
  return 0;
}
