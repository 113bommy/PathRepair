#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
using namespace std;
const double pi = 3.141592653589793238460;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long N = 3e5 + 5;
long long dx[4] = {0, 0, +1, -1};
long long dy[4] = {+1, -1, 0, 0};
long long n, k;
vector<long long> v;
long long ck(long long x) {
  long long sm = 0;
  for (auto& i : v) {
    sm += max(0ll, x - i);
  }
  if (sm > k) {
    return 0;
  }
  return 1;
}
long long bs(long long l, long long h) {
  long long x = 0;
  while (l <= h) {
    long long md = (l + h) / 2;
    if (ck(md)) {
      x = md;
      l = md + 1;
    } else
      h = md - 1;
  }
  return x;
}
long long ckk(long long x) {
  long long sm = 0;
  for (auto& i : v) {
    sm += max(0ll, i - x);
  }
  if (sm > k) {
    return 0;
  }
  return 1;
}
long long bss(long long l, long long h) {
  long long x = 0;
  while (l <= h) {
    long long md = (l + h) / 2;
    if (ckk(md)) {
      x = md;
      h = md - 1;
    } else
      l = md + 1;
  }
  return x;
}
void fun() {
  cin >> n >> k;
  ;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ;
    v.push_back(x);
  }
  sort((v).begin(), (v).end());
  long long p = bs(1, 2 * 1e9);
  long long tm = k;
  for (auto& i : v) {
    if (p > i) {
      long long d = p - i;
      tm -= d;
      i = p;
    }
  }
  sort((v).begin(), (v).end());
  long long i = 0;
  while (tm > 0) {
    v[i]++;
    i++;
    tm--;
  }
  p = bss(1, 2 * 1e9);
  tm = k;
  for (auto& i : v) {
    if (p < i) {
      long long d = i - p;
      tm -= d;
      i = p;
    }
  }
  sort((v).begin(), (v).end(), greater<long long>());
  i = 0;
  while (tm > 0) {
    v[i]--;
    i++;
    tm--;
  }
  long long d = *max_element((v).begin(), (v).end()) -
                *min_element((v).begin(), (v).end());
  cout << d << '\n';
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    fun();
  }
  return 0;
}
