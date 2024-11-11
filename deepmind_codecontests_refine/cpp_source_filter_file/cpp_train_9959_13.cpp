#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << " " << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void inp_out() {}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  inp_out();
  long long int n, w;
  cin >> n >> w;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long int val = 0, mx = w, mn = 0;
  for (long long int i = 0; i < n; ++i) {
    if (abs(a[i]) > w) {
      cout << 0;
      return 0;
    }
    val += a[i];
    if (val > w) {
      cout << 0;
      return 0;
    }
    long long int val1 = min(w, w - val);
    long long int val2 = max(0ll, -val);
    mx = min(val1, mx);
    mn = max(val2, mn);
  }
  cout << (mx - mn + 1);
  return 0;
}
