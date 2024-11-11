#include <bits/stdc++.h>
using namespace std;
long long n, k, ai;
vector<long long> data;
int32_t main() {
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> ai;
    data.push_back(ai);
  }
  long long ba = 1;
  long long ans;
  for (long long i = 2; i <= 1e5; i++) {
    ans = 0;
    for (long long j = 0; j < n; j++) {
      long long mn = data[j] / i;
      if (data[j] % i != 0) mn++;
      long long money = mn * i - data[j];
      ans += money;
    }
    if (ans <= k) ba = i;
  }
  vector<pair<long long, long long> > ev;
  for (long long i = 1; i < 10000; i++) {
    for (long long j = 0; j < n; j++) {
      long long start = data[j] / i;
      if (data[j] % i != 0) start++;
      if (start <= 100000) continue;
      pair<long long, long long> p = make_pair(start, j);
      ev.push_back(p);
    }
  }
  vector<long long> pls, times;
  sort(ev.begin(), ev.end());
  long long pl = 0;
  for (long long j = 0; j < n; j++) {
    long long del = data[j] / 100000;
    if (data[j] % 100000 != 0) del++;
    pl += del;
    pls.push_back(del);
    times.push_back(100000);
  }
  long long nt = 1e5;
  long long nole = 0;
  for (long long i = 0; i < ev.size(); i++) {
    long long tt = ev[i].first;
    long long where = ev[i].second;
    long long new_ans = ans + max(nole, tt - nt) * pl;
    if (new_ans > k && ans <= k) {
      long long can = (k - ans) / pl;
      ba = can + nt;
    }
    if (new_ans <= k) ba = tt - 1;
    ans = new_ans;
    if (times[where] != tt) {
      long long lost = tt * pls[where] - k;
      long long better = data[where] / tt;
      if (data[where] % tt != 0) better++;
      long long nost = tt * better - k;
      pl += better - pls[where];
      ans -= (lost - nost);
      pls[where] = better;
    }
    nt = tt;
    times[where] = tt;
  }
  sort(data.begin(), data.end());
  long long left = data[data.size() - 1];
  long long right = 1e12;
  while (right - left > 1) {
    long long that = 0;
    long long mid = (left + right) / 2;
    for (long long i = 0; i < n; i++) {
      that += mid - data[i];
    }
    if (that > k)
      right = mid;
    else
      left = mid;
  }
  if (left != data[data.size() - 1]) ba = left;
  cout << ba << endl;
  return 0;
}
