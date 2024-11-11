#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5e5 + 55;
long long n, c, a[MAXN], cnt[MAXN];
map<long long, vector<long long>> positions;
long long get(long long l, long long r) {
  if (l > r) {
    return 0;
  }
  long long ret = cnt[r];
  if (l > 0) {
    ret -= cnt[l - 1];
  }
  return ret;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> c;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    positions[a[i]].push_back(i);
    if (i > 0) {
      cnt[i] = cnt[i - 1];
    }
    if (a[i] == c) {
      cnt[i]++;
    }
  }
  long long ret = 1;
  for (auto &x : positions) {
    if (x.first == c) {
      ret = max(ret, (long long)x.second.size());
      continue;
    }
    long long l = 0;
    for (long long i = 0; i < x.second.size(); i++) {
      long long curr = i - l + 1;
      curr += get(0, x.second[l] - 1);
      curr += get(x.second[i] + 1, n - 1);
      if (i - l + 1 <= get(x.second[l], x.second[i])) {
        l = i;
        curr = 1;
        curr += get(0, x.second[l] - 1);
        curr += get(x.second[i] + 1, n - 1);
      }
      ret = max(ret, curr);
    }
  }
  cout << ret << endl;
  return 0;
}
