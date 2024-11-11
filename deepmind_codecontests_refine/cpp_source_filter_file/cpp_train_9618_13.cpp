#include <bits/stdc++.h>
using namespace std;
long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const long long maxn = 1e6 + 10;
long long grundy[maxn];
int32_t main() {
  string s;
  cin >> s;
  long long n = s.size();
  for (long long i = 3; i <= n; i++) {
    set<long long> st;
    for (long long j = 1; j <= i / 2; j++)
      st.insert(grundy[j] ^ grundy[i - j - 1]);
    long long ptr = 0;
    while (st.count(ptr)) ptr++;
    grundy[i] = ptr;
  }
  for (long long i = 1; i < n - 1; i++) {
    if (s[i - 1] == s[i + 1]) {
      long long xo = 0;
      long long cnt = 0;
      for (long long j = 0; j < n; j++) {
        if (j > 0 && j + 1 < n && j - i && s[j - 1] == s[j + 1])
          cnt++;
        else
          xo ^= grundy[cnt + 1], cnt = 1;
      }
      if (xo == 0) {
        cout << "First\n";
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  cout << "Second\n";
}
