#include <bits/stdc++.h>
using namespace std;
long long n, m, seed, vmax;
long long rnd() {
  long long ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
long long exp(long long x, long long y, long long m) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return exp(x * x % m, y / 2, m);
  else
    return x * exp(x, y - 1, m) % m;
}
void solve() {
  cin >> n >> m >> seed >> vmax;
  map<int, long long> A;
  vector<int> a(n + 1);
  for (int i = 1; i <= (n); ++i) {
    a[i] = (rnd() % vmax) + 1;
    A.insert({i, a[i]});
  }
  A[n + 1] = 0;
  while (m--) {
    int op = (rnd() % 4) + 1;
    int l = (rnd() % n) + 1;
    int r = (rnd() % n) + 1;
    int x, y;
    if (l > r) swap(l, r);
    if (op == 3)
      x = (rnd() % (r - l + 1)) + 1;
    else
      x = (rnd() % vmax) + 1;
    if (op == 4) y = (rnd() % vmax) + 1;
    auto it_l = A.upper_bound(l);
    it_l--;
    if (it_l->first != l) {
      A[l] = it_l->second;
      it_l++;
    }
    auto it_r = A.upper_bound(r + 1);
    it_r--;
    if (it_r->first != r + 1) {
      A[r + 1] = it_r->second;
      it_r++;
    }
    switch (op) {
      case 1:
        while (it_l != it_r) {
          it_l->second += x;
          it_l++;
        }
        break;
      case 2:
        it_l->second = x;
        it_l++;
        while (it_l != it_r) {
          A.erase(it_l++);
        }
        break;
      case 3: {
        vector<pair<long long, int>> v;
        int prev = l;
        long long val = it_l->second;
        it_l++;
        while (it_l != it_r) {
          v.push_back({val, it_l->first - prev});
          val = it_l->second;
          prev = it_l->first;
          it_l++;
        }
        v.push_back({val, it_l->first - prev});
        sort(v.begin(), v.end());
        int cnt = 0;
        for (int i = 0; i <= ((int)(v).size() - 1); ++i) {
          cnt += v[i].second;
          if (cnt >= x) {
            cout << v[i].first << endl;
            break;
          }
        }
      } break;
      case 4: {
        vector<tuple<long long, int>> v;
        int prev = l;
        long long val = it_l->second;
        it_l++;
        while (it_l != it_r) {
          v.push_back({val, it_l->first - prev});
          val = it_l->second;
          prev = it_l->first;
          it_l++;
        }
        v.push_back({val, it_l->first - prev});
        long long ans = 0;
        for (int i = 0; i <= ((int)(v).size() - 1); ++i) {
          ans += ((long long)exp(get<0>(v[i]), x, y) * get<1>(v[i]) % y);
          ans %= y;
        }
        cout << ans << endl;
        break;
      }
    }
  }
}
int main() {
  clock_t beg = clock();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  clock_t end = clock();
  fprintf(stderr, "%lf\n", (double)(end - beg) / CLOCKS_PER_SEC);
}
