#include <bits/stdc++.h>
using namespace std;
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
int main() {
  ios_base::sync_with_stdio;
  cin.tie(NULL);
  cout.tie(0);
  long long n, s, t;
  cin >> n >> s >> t;
  vector<long long> v(n);
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    m[i + 1] = v[i];
  }
  long long ans = 0;
  long long k = v[s - 1];
  bool jj = 0;
  if (s == t)
    cout << "0\n";
  else {
    ans++;
    for (long long i = 0; i < n; i++) {
      if (k == t) {
        jj = 1;
        break;
      } else {
        k = v[k - 1];
        ans++;
      }
    }
    if (jj)
      cout << ans << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
