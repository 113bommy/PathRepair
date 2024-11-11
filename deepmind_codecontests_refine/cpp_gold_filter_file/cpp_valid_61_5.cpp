#include <bits/stdc++.h>
using namespace std;
template <typename A1>
void prn(A1&& arg) {
  cout << arg << '\n';
}
template <typename A1, typename... A>
void prn(A1&& arg, A&&... args) {
  cout << arg << ' ';
  prn(args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    string tmp = s;
    long long ans = 0;
    if (n == 1) {
      if (s[0] == '?')
        prn('B');
      else
        prn(s);
      continue;
    }
    if (tmp[0] == '?') tmp[0] = 'B';
    for (long long i = 1; i < n; i++) {
      if (tmp[i] == '?') {
        if (tmp[i - 1] == 'B')
          tmp[i] = 'R';
        else
          tmp[i] = 'B';
      } else if (tmp[i] == tmp[i - 1])
        ans++;
    }
    string tmp2 = s;
    long long ans2 = 0;
    if (tmp2[0] == '?') tmp2[0] = 'R';
    for (long long i = 1; i < n; i++) {
      if (tmp2[i] == '?') {
        if (tmp2[i - 1] == 'B')
          tmp2[i] = 'R';
        else
          tmp2[i] = 'B';
      } else if (tmp2[i] == tmp2[i - 1])
        ans2++;
    }
    (ans < ans2) ? prn(tmp) : prn(tmp2);
  }
}
