#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, A, cf, cm, m;
pair<long long, long long> a[N];
long long prefix[N], suffix[N];
long long ans = 0;
long long full = -1;
long long min_value = -1;
long long num_of_mins = -1;
long long calc_start_index(long long take_as_full, long long value) {
  long long l = take_as_full + 1;
  long long r = n;
  while (l < r) {
    long long mid_index = (l + r) / 2;
    if (a[mid_index].first <= value) {
      r = mid_index;
    } else {
      l = mid_index + 1;
    }
  }
  return l;
}
bool comp(pair<long long, long long> x, pair<long long, long long> y) {
  return x.second < y.second;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> A >> cf >> cm >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (long long i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + a[i].first;
  }
  for (long long i = n; i >= 1; i--) {
    suffix[i] = suffix[i + 1] + a[i].first;
  }
  for (long long take_as_full = 0; take_as_full <= n; take_as_full++) {
    long long force_sum = take_as_full * cf;
    long long rem_coins = m;
    if (take_as_full > 0) {
      rem_coins -= (take_as_full * A) - prefix[take_as_full];
    }
    if (rem_coins < 0) {
      break;
    }
    long long other_sum = a[n].first * cm;
    if (take_as_full == n) {
      other_sum = A * cm;
    }
    if (take_as_full < n) {
      long long lo = 0;
      long long hi = A;
      while (lo < hi) {
        long long mid = (lo + hi + 1) / 2;
        long long index = calc_start_index(take_as_full, mid);
        long long how_much = mid * (n - index + 1) - suffix[index];
        if (how_much <= rem_coins) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }
      other_sum = lo * cm;
      if (ans < force_sum + other_sum) {
        ans = force_sum + other_sum;
        full = take_as_full;
        min_value = lo;
        num_of_mins = calc_start_index(take_as_full, lo);
      }
    } else {
      if (ans < force_sum + other_sum) {
        ans = force_sum + other_sum;
        full = take_as_full;
        min_value = -1;
        num_of_mins = 0;
      }
    }
  }
  cout << ans << "\n";
  for (long long i = 1; i <= full; i++) {
    a[i].first = A;
  }
  if (num_of_mins > 0) {
    for (long long i = 1; i <= num_of_mins; i++) {
      a[n - i + 1].first = min_value;
    }
  }
  sort(a + 1, a + n + 1, comp);
  for (long long i = 1; i <= n; i++) {
    cout << a[i].first << " ";
  }
  cout << "\n";
}
