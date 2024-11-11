#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long n, m, ans;
string str;
long long c[10], s;
vector<long long> v;
long long solve() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    long long a;
    cin >> a;
    c[a]++;
    s += a;
    v.push_back(a);
  }
  if (!c[0]) {
    cout << "-1";
    return 0;
  }
  if (s % 3 == 0) {
    ;
  } else if (s % 3 == 1) {
    long long f = 1;
    if (c[1])
      c[1]--;
    else if (c[4])
      c[4]--;
    else if (c[7])
      c[7]--;
    else if (c[2] >= 2) {
      c[2] -= 2;
    } else if (c[2] && c[5]) {
      c[2]--;
      c[5]--;
    } else if (c[5] >= 2) {
      c[5] -= 2;
    } else if (c[2] && c[7]) {
      c[2]--;
      c[7]--;
    } else if (c[5] && c[7]) {
      c[5]--;
      c[7]--;
    } else if (c[7] >= 2) {
      c[7] -= 2;
    } else
      f = 0;
    if (!f) {
      cout << -1;
      return 0;
    }
  } else {
    long long f = 1;
    if (c[2])
      c[2]--;
    else if (c[5])
      c[5]--;
    else if (c[8])
      c[8]--;
    else if (c[1] >= 2) {
      c[1]--;
      c[1]--;
    } else if (c[1] && c[4]) {
      c[1]--;
      c[4]--;
    } else if (c[4] >= 2) {
      c[4] -= 2;
    } else if (c[1] && c[7]) {
      c[1]--;
      c[7]--;
    } else if (c[4] && c[7]) {
      c[4]--;
      c[7]--;
    } else if (c[7] >= 2) {
      c[7] -= 2;
    } else
      f = 0;
    if (!f) {
      cout << -1;
      return 0;
    }
  }
  long long f = 1;
  for (long long i = 1; i <= 9; ++i)
    if (c[i]) f = 0;
  if (f) {
    cout << 0;
    return 0;
  }
  for (long long j = 9; j >= 0; --j) {
    for (long long i = 1; i <= c[j]; ++i) {
      cout << j;
    }
  }
  return 0;
}
signed main() {
  ios::sync_with_stdio(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
