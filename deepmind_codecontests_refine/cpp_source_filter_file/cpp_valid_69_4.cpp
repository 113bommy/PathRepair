#include <bits/stdc++.h>
using namespace std;
long long inf = 1e9, mod = 1e9 + 7;
inline long long mn(long long x, long long y) { return (x > y) ? y : x; }
int main() {
  srand(time(nullptr));
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long st2 = 1;
  vector<string> stt;
  while (st2 <= 1e13) {
    stt.push_back(to_string(st2));
    st2 *= 2;
  }
  long long test;
  cin >> test;
  while (test--) {
    long long i, j, k;
    string n;
    cin >> n;
    long long ans = inf;
    for (i = 0; i < stt.size(); i++) {
      string st = stt[i];
      for (j = 0; j <= min(st.length(), n.length()); j++) {
        long long it = 0;
        for (k = 0; it < j && k < n.length(); k++)
          if (n[k] == st[it]) it++;
        if (it < j) break;
      }
      j--;
      ans = mn(ans, n.length() - j + st.length() - j);
    }
    cout << ans << '\n';
  }
}
