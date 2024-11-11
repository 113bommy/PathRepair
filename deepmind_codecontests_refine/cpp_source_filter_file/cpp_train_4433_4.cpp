#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.tie(NULL);
  long long int n, i, j, k, ans = 0, q = 0;
  cin >> n;
  string s, t;
  cin >> s;
  long long int v[20];
  memset(v, 0, sizeof(v));
  ;
  for (auto it : s) {
    if (it == '?')
      q++;
    else
      v[it - 'A']++;
  }
  if (v[0] <= n / 4 && v[2] <= n / 4 && v[2] <= n / 4 && v[19] <= n / 4 &&
      n % 4 == 0) {
    for (i = 0; i < n; i++) {
      if (s[i] != '?')
        t += s[i];
      else if (v[0] < n / 4)
        t += 'A' + 0, v[0]++;
      else if (v[2] < n / 4)
        t += 'A' + 2, v[2]++;
      else if (v[6] < n / 4)
        t += 'A' + 6, v[6]++;
      else if (v[19] < n / 4)
        t += 'A' + 19, v[19]++;
    }
    cout << t;
  } else
    cout << "===";
  return 0;
}
