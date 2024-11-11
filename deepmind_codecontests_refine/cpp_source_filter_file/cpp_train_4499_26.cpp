#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  int l = v.size();
  for (int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
const long double PI = 3.1415926535897932384626433832795;
long long f[100], n, t, s[100], dp1[100], dp2[100], k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i < 90; i++) f[i] = f[i - 1] + f[i - 2];
  cin >> t;
  while (t--) {
    cin >> n;
    k = 0;
    for (int i = 89; i >= 0; i--)
      if (n >= f[i]) {
        n -= f[i];
        s[++k] = i;
      }
    dp1[0] = 1;
    dp2[0] = 0;
    reverse(s + 1, s + k + 1);
    for (int i = 1; i <= k; i++) {
      dp1[i] = dp1[i - 1] + dp2[i - 1];
      dp2[i] = dp1[i - 1] * (s[i] - s[i - 1] - 1) / 2 +
               dp2[i - 1] * (s[i] - s[i - 1]) / 2;
    }
    cout << dp1[k] + dp2[k] << '\n';
  }
  return 0;
}
