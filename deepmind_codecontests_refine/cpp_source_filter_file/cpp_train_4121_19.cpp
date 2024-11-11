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
vector<long long> v[N];
long long a[N], b[N];
void g(long long x, long long p, long long l, long long d) {
  long long ct = -1;
  for (auto& i : v[x]) {
    if (i == p) continue;
    ct++;
    if (ct == d) ct++;
    long long ck = 0;
    if (ct == 0) {
      a[i] = a[x];
      b[i] = b[x] + (1LL << l);
      ck = 1;
    }
    if (ct == 1) {
      a[i] = a[x];
      b[i] = b[x] - (1ll << l);
      ck = 0;
    }
    if (ct == 2) {
      a[i] = a[x] + (1LL << l);
      b[i] = b[x];
      ck = 3;
    }
    if (ct == 3) {
      a[i] = a[x] - (1LL << l);
      b[i] = b[x];
      ck = 2;
    }
    g(i, x, l - 1, ck);
  }
}
void fun() {
  long long n;
  cin >> n;
  ;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    long long y;
    cin >> y;
    ;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (long long i = 1; i <= n + 1; i++) {
    if ((int(v[i].size())) > 4) {
      cout << "NO" << '\n';
      return;
    }
  }
  a[1] = 1, b[1] = 1;
  g(1, -1, 40, -1);
  cout << "YES" << '\n';
  for (long long i = 1; i < n + 1; i++) {
    cout << a[i] << " ";
    ;
    cout << b[i] << '\n';
    ;
  }
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
