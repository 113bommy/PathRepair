#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first - a.second) > (b.first - b.second);
}
std::vector<long long int> temp[10002];
long long int fenwick[10002];
void update(long long int n, long long int val) {
  for (; n < 10002; n += (n & (-n))) {
    fenwick[n] += val;
  }
}
long long int get_val(long long int n) {
  long long int ans = 0;
  for (; n > 0; n -= (n & (-n))) ans += fenwick[n];
  return ans;
}
long long int query(long long int l, long long int r) {
  return get_val(r) - get_val(l - 1);
}
void reset() {
  memset(fenwick, 0, sizeof(fenwick));
  for (int i = 0; i < 10002; i++) temp[i].clear();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int>> hor[10002], ver[10002];
  for (long long int i = 0; i < n; ++i) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    a += 5001;
    b += 5001;
    c += 5001;
    d += 5001;
    if (b == d)
      hor[b].push_back({min(a, c), max(a, c)});
    else
      ver[a].push_back({min(b, d), max(b, d)});
    ;
  }
  long long int ans = 0;
  for (long long int y = 1; y < 10002; y++) {
    for (auto it : hor[y]) {
      reset();
      for (long long int x = it.first; x <= it.second; ++x) {
        for (auto it2 : ver[x]) {
          if (it2.first <= y && it2.second > y) {
            update(x, 1);
            temp[it2.second].push_back(x);
          }
        }
      }
      for (long long int i = y + 1; i < 10002; i++) {
        for (auto it2 : hor[i]) {
          long long int val = query(it2.first, it2.second);
          ans += (val * (val - 1)) / 2;
        }
        for (long long int it2 : temp[i]) update(it2, -1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
