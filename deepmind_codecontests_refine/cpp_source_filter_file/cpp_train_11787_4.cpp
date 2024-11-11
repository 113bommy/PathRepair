#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long bin(long long a, long long b) {
  if (b == 0) return 1;
  if (b & 1) return (a * bin((a * a) % mod, b / 2)) % mod;
  return (1 * bin((a * a) % mod, b / 2)) % mod;
}
void I_m_Beast() {
  long long n, m, a;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  vector<int> vec(n + 2, 0);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    if (vec[A[i] - 1] == 0) {
      vec[A[i] - 1] = 1;
      mx++;
    } else if (vec[A[i]] == 0) {
      vec[A[i]] = 1;
      mx++;
    } else if (vec[A[i] + 1] == 0) {
      vec[A[i] + 1]++;
      mx++;
    }
  }
  set<int> st(A, A + n);
  vector<int> v(st.begin(), st.end());
  int mn = 0;
  n = v.size();
  int i = 0;
  while (i < n) {
    if (i + 2 < n) {
      if (v[i] + 1 == v[i + 1] && v[i + 1] + 1 == v[i + 2]) {
        mn++;
        i += 3;
      } else if (v[i] + 1 == v[i + 1]) {
        mn++;
        i += 2;
      } else {
        mn++;
        i++;
      }
    } else if (i + 1 < n) {
      if (v[i] + 1 == v[i + 1]) {
        mn++;
        i += 2;
      } else {
        mn++;
        i++;
      }
    } else {
      i++;
      mn++;
    }
  }
  cout << mn << " " << mx << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    I_m_Beast();
  }
  return 0;
}
