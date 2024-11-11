#include <bits/stdc++.h>
using namespace std;
map<long long, long long> st;
long long ans, a, b;
int n;
const long long base = 20000LL;
int main() {
  cin >> n >> a >> b;
  st[0] = 1;
  n--;
  if (a > b) swap(a, b);
  if (!a) {
    cout << b * (long long)(n - 1) << endl;
    return 0;
  }
  if (a * base < b) {
    for (int t = 0; n; t++) {
      long long N = (b / a) + 1;
      N = min(N, (long long)n);
      ans += N * (N - 1) / 2LL * a + N * b * (long long)t;
      ans += N * (a + b);
      n -= N;
    }
  } else
    while (n > 0) {
      map<long long, long long>::iterator q = st.begin();
      long long A = q->first, B = q->second;
      ans += min((long long)n, B) * A + (long long)(a + b);
      n -= B;
      st.erase(q);
      st[A + (long long)a] += B;
      st[A + (long long)b] += B;
    }
  cout << ans << endl;
  return 0;
}
