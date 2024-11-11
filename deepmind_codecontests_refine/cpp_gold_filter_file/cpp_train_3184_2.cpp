#include <bits/stdc++.h>
using namespace std;
int main() {
  long long begin, end, t;
  scanf("%I64d%I64d%I64d", &begin, &end, &t);
  vector<long long> per;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long t;
    scanf("%I64d", &t);
    per.push_back(t);
  }
  if (n == 0) {
    cout << begin << endl;
    return 0;
  }
  long long till = begin;
  for (int i = 0; i < n; i++) {
    if (per[i] <= till)
      till += t;
    else {
      cout << till;
      return 0;
    }
    if (till > end) break;
  }
  till = begin;
  long long ans = 1, MIN = 1e13, now;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      now = till - (per[i] - 1);
      till += t;
    } else {
      if (per[i] != per[i - 1]) {
        now = till - (per[i] - 1);
        till += t;
      } else
        till += t;
    }
    if (till > end) break;
    if (now < MIN) {
      MIN = now;
      ans = per[i] - 1;
    }
  }
  if (till + t <= end)
    cout << till << endl;
  else
    cout << ans << endl;
  return 0;
}
