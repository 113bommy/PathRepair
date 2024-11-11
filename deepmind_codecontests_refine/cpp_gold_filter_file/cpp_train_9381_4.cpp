#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void printl(T a, char c = '\n') {
  cout << a << c;
}
template <typename T>
inline void print(T a, char c = ' ') {
  cout << a << c;
}
template <typename T1, typename T2>
inline void print(T1 a, T2 b) {
  cout << a << " " << b << endl;
}
signed main() {
  map<string, pair<long long, string>> mp;
  long long n;
  cin >> n;
  string s;
  while (n--) {
    cin >> s;
    long long len = (long long)s.size();
    for (long long i = 0; i < len; i++) {
      for (long long j = i; j < len; j++) {
        string help = s.substr(i, j - i + 1);
        if (mp.count(help)) {
          if (mp[help].second != s) {
            mp[help].second = s;
            mp[help].first++;
          }
        } else {
          mp[help].first = 1;
          mp[help].second = s;
        }
      }
    }
  }
  long long q;
  cin >> q;
  while (q--) {
    cin >> s;
    if (mp.count(s)) {
      cout << (mp[s].first) << " ";
      printl(mp[s].second);
    } else
      cout << 0 << " -" << '\n';
  }
  return 0;
}
