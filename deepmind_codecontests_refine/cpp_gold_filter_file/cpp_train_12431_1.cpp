#include <bits/stdc++.h>
using namespace std;
long long mult(long long a, long long b, long long p = (int)(1e9 + 7)) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = (int)(1e9 + 7)) {
  return (a % p + b % p) % p;
}
long long fpow(long long n, long long k, long long p = (int)(1e9 + 7)) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = (int)(1e9 + 7)) {
  return fpow(a, p - 2, p);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a[300005] = {0};
  set<long long> st;
  set<long long>::iterator it;
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i < n + 1; i++) {
    st.insert(i);
  }
  long long l, r, x;
  while (m--) {
    cin >> l >> r >> x;
    it = st.lower_bound(l);
    while (it != st.end()) {
      if (*it > r) break;
      if (*it == x) {
        it++;
        continue;
      }
      a[*it] = x;
      st.erase(it++);
    }
  }
  for (int i = 1; i < n + 1; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
