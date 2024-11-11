#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long ts, tf, t, n, wait = 1e12, prev, time, ans = -1;
  cin >> ts >> tf >> t >> n;
  if (n == 0)
    ans = ts;
  else {
    cin >> prev;
    if (prev > 0 && prev <= ts) {
      wait = ts - (prev - 1);
      ans = prev - 1;
    }
    if (prev > ts) {
      wait = 0;
      ans = ts;
    }
    time = ts + t;
    bool gap = false;
    for (int i = 1; i < n; i++) {
      unsigned long long cur;
      cin >> cur;
      if (gap) continue;
      if (cur > time && time + t <= tf) {
        ans = time;
        gap = true;
      } else {
        time += t;
        if (cur - 1 == prev && time - prev < wait && time <= tf) {
          wait = time - prev;
          ans = prev;
        }
        if (cur > prev + 1 && time - (cur - 1) < wait && time <= tf) {
          wait = time - (cur - 1);
          ans = cur - 1;
        }
        prev = cur;
      }
    }
    if (!gap && time + t <= tf) {
      ans = time;
    }
  }
  cout << ans << endl;
  return 0;
}
