#include <bits/stdc++.h>
using namespace std;
int n, t, zafo, last_pos;
int c[10];
int cnt[2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 4; i++) cin >> c[i];
  if (c[0] == c[3] && c[3] == 0) {
    if (c[1] == 1 && c[2] == 0)
      cout << "01";
    else if (c[1] == 0 && c[2] == 1)
      cout << "10";
    else if (!c[1] && !c[2])
      cout << "0";
    else
      cout << "Impossible" << '\n';
    return 0;
  }
  t = sqrt(c[0] * 2);
  if (c[0] == 0) {
    if (c[2] == 0 && c[1] == 0) t = -1;
  }
  if (t * (t + 1) != c[0] * 2) return cout << "Impossible" << '\n', 0;
  cnt[0] = t + 1;
  t = sqrt(c[3] * 2);
  if (c[3] == 0) {
    if (c[2] == 0 && c[1] == 0) t = -1;
  }
  if (t * (t + 1) != c[3] * 2) return cout << "Impossible" << '\n', 0;
  cnt[1] = t + 1;
  if (cnt[0] * cnt[1] != c[1] + c[2]) return cout << "Impossible" << '\n', 0;
  if (cnt[1] != 0) {
    zafo = c[2] / cnt[1];
    last_pos = c[2] - cnt[1] * zafo;
  }
  for (int i = 1; i <= cnt[0] - zafo - (last_pos > 0); i++) cout << 0;
  for (int i = 1; i <= last_pos; i++) cout << 1;
  if (last_pos != 0) {
    cout << 0;
  }
  for (int i = last_pos + 1; i <= cnt[1]; i++) cout << 1;
  for (int i = 1; i <= zafo; i++) cout << 0;
}
