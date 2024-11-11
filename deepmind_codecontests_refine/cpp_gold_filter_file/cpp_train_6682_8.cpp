#include <bits/stdc++.h>
using namespace std;
long long k, w, e, maxi = INT_MIN, mini = LONG_LONG_MAX, cnt1, cnt2, x, y, l, t;
vector<long long> v;
void lucky(long long i) {
  if (i) v.push_back(i);
  if (i > (long long)1e10) return;
  lucky(i * 10 + 4);
  lucky(i * 10 + 7);
}
int lower(vector<long long>& v, long long k) {
  vector<long long>::iterator low;
  low = lower_bound(v.begin(), v.end(), k);
  long long h = low - v.begin();
  return h;
}
int main() {
  lucky(0);
  sort(v.begin(), v.end());
  cin >> k >> e;
  long long sum = 0;
  while (k <= e) {
    int o = lower(v, k);
    sum += (v[o] * (min(v[o], e) - k + 1));
    k = v[o] + 1;
  }
  cout << sum << endl;
}
