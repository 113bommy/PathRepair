#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int mod = 1e9 + 7;
const long long MAX = 5e18;
const long long MIN = -MAX;
const int imax = 2e9 + 100;
int main() {
  time_t t1, t2;
  t1 = clock();
  ios_base::sync_with_stdio(0);
  long long n, x, k;
  cin >> n >> x >> k;
  long long a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<long long> b;
  for (int i = 1; i <= n; i++) b.push_back(a[i]);
  sort(b.begin(), b.end());
  long long ANS = 0;
  for (int i = 1; i <= n; i++) {
    long long lo = 0, hi = n - 1, mid, ans = n;
    long long ceil_ai = ceil((float)a[i] / x) * x;
    long long num = ceil_ai + (k - 1) * x;
    num = max(num, a[i] + 1);
    long long start = num;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (b[mid] >= num) {
        ans = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    long long lb = ans;
    lo = 0, hi = n - 1, ans = -1;
    num = ceil_ai + k * x - 1;
    long long end = num;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (b[mid] <= num) {
        ans = mid;
        lo = mid + 1;
      } else
        hi = mid - 1;
    }
    if (lb == n or ans == -1) continue;
    if (lb <= ans) ANS += ans - lb + 1;
  }
  multiset<long long> ms;
  for (int i = 1; i <= n; i++) ms.insert(a[i]);
  map<long long, int> mp;
  for (int i = 1; i <= n; i++) {
    if (mp.find(a[i]) == mp.end()) {
      if (a[i] % x == 0 and k == 1)
        ANS += 1ll * ms.count(a[i]) * ms.count(a[i]);
      else if (k == 0 and a[i] % x != 0)
        ANS += 1ll * ms.count(a[i]) * ms.count(a[i]);
    }
    mp[a[i]];
  }
  cout << ANS << endl;
  t2 = clock();
  cerr << "time taken: " << t2 - t1 << endl;
  return 0;
}
