#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int r, g, b;
    cin >> r >> g >> b;
    long long int red[r], green[g], blue[b];
    for (long long int i = 0; i < r; i++) cin >> red[i];
    for (long long int i = 0; i < g; i++) cin >> green[i];
    for (long long int i = 0; i < b; i++) cin >> blue[i];
    sort(red, red + r);
    sort(green, green + g);
    sort(blue, blue + b);
    long long int ans = LLONG_MAX;
    for (long long int i = 0; i < r; i++) {
      long long int g1, s1, g2, s2, c = red[i];
      g1 = min(g - 1,
               (long long int)(lower_bound(green, green + g, red[i]) - green));
      s1 = max(0ll, g1 - 1ll);
      g2 = min(b - 1,
               (long long int)(lower_bound(blue, blue + b, red[i]) - blue));
      s2 = max(0ll, g2 - 1ll);
      g1 = green[g1], s1 = green[s1];
      g2 = blue[g2], s2 = blue[s2];
      ans = min(ans, (g1 - g2) * (g1 - g2) + (g1 - c) * (g1 - c) +
                         (g2 - c) * (g2 - c));
      ans = min(ans, (g1 - s2) * (g1 - s2) + (g1 - c) * (g1 - c) +
                         (s2 - c) * (s2 - c));
      ans = min(ans, (s1 - s2) * (s1 - s2) + (s1 - c) * (s1 - c) +
                         (s2 - c) * (s2 - c));
      ans = min(ans, (g2 - s1) * (g2 - s1) + (g2 - c) * (g2 - c) +
                         (s1 - c) * (s1 - c));
    }
    for (long long int i = 0; i < g; i++) {
      long long int g1, s1, g2, s2, c = green[i];
      g1 = min(g - 1,
               (long long int)(lower_bound(red, red + r, green[i]) - red));
      s1 = max(0ll, g1 - 1ll);
      g2 = min(b - 1,
               (long long int)(lower_bound(blue, blue + b, green[i]) - blue));
      s2 = max(0ll, g2 - 1ll);
      g1 = red[g1], s1 = red[s1];
      g2 = blue[g2], s2 = blue[s2];
      ans = min(ans, (g1 - g2) * (g1 - g2) + (g1 - c) * (g1 - c) +
                         (g2 - c) * (g2 - c));
      ans = min(ans, (g1 - s2) * (g1 - s2) + (g1 - c) * (g1 - c) +
                         (s2 - c) * (s2 - c));
      ans = min(ans, (s1 - s2) * (s1 - s2) + (s1 - c) * (s1 - c) +
                         (s2 - c) * (s2 - c));
      ans = min(ans, (g2 - s1) * (g2 - s1) + (g2 - c) * (g2 - c) +
                         (s1 - c) * (s1 - c));
    }
    for (long long int i = 0; i < b; i++) {
      long long int g1, s1, g2, s2, c = blue[i];
      g1 =
          min(g - 1, (long long int)(lower_bound(red, red + r, blue[i]) - red));
      s1 = max(0ll, g1 - 1ll);
      g2 = min(b - 1,
               (long long int)(lower_bound(green, green + g, blue[i]) - green));
      s2 = max(0ll, g2 - 1ll);
      g1 = red[g1], s1 = red[s1];
      g2 = green[g2], s2 = green[s2];
      ans = min(ans, (g1 - g2) * (g1 - g2) + (g1 - c) * (g1 - c) +
                         (g2 - c) * (g2 - c));
      ans = min(ans, (g1 - s2) * (g1 - s2) + (g1 - c) * (g1 - c) +
                         (s2 - c) * (s2 - c));
      ans = min(ans, (s1 - s2) * (s1 - s2) + (s1 - c) * (s1 - c) +
                         (s2 - c) * (s2 - c));
      ans = min(ans, (g2 - s1) * (g2 - s1) + (g2 - c) * (g2 - c) +
                         (s1 - c) * (s1 - c));
    }
    cout << ans << endl;
  }
  return 0;
}
