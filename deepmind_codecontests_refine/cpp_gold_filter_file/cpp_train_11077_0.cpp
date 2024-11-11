#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  string ans = "";
  long long time, n, m, s, f;
  cin >> n >> m >> s >> f;
  vector<int> t(m), l(m), r(m);
  for (long long i = 0; i < m; i++) {
    cin >> t[i] >> l[i] >> r[i];
  }
  if (s < f) {
    time = 1;
    vector<int>::iterator it;
    while (1) {
      it = lower_bound((t).begin(), (t).end(), time);
      if (it == t.end()) {
        ans += string(f - s, 'R');
        cout << ans;
        return 0;
      }
      if (*it > time) {
        if (f - s <= *it - time) {
          ans += string(f - s, 'R');
          cout << ans;
          return 0;
        } else {
          s += *it - time;
          ans += string(*it - time, 'R');
          time = *it;
        }
      }
      if ((s >= l[it - t.begin()] && s <= r[it - t.begin()]) ||
          (s + 1 <= r[it - t.begin()] && s + 1 >= l[it - t.begin()])) {
        ans += "X";
      } else {
        ans += "R";
        s++;
        if (f == s) {
          cout << ans;
          return 0;
        }
      }
      time++;
    }
  } else {
    time = 1;
    vector<int>::iterator it;
    while (1) {
      it = lower_bound((t).begin(), (t).end(), time);
      if (it == t.end()) {
        ans += string(s - f, 'L');
        cout << ans;
        return 0;
      }
      if (*it > time) {
        if (s - f <= *it - time) {
          ans += string(s - f, 'L');
          cout << ans;
          return 0;
        } else {
          s -= *it - time;
          ans += string(*it - time, 'L');
          time = *it;
        }
      }
      if ((s >= l[it - t.begin()] && s <= r[it - t.begin()]) ||
          (s - 1 <= r[it - t.begin()] && s - 1 >= l[it - t.begin()])) {
        ans += "X";
      } else {
        ans += "L";
        s--;
        if (f == s) {
          cout << ans;
          return 0;
        }
      }
      time++;
    }
  }
  return 0;
}
