#include <bits/stdc++.h>
using namespace std;
const long long logN = 20;
const long long M = 1000000007;
const long long INF = 1e18;
const long long N = 100005;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long A[n];
  for (long long i = 0; i < n; i++) cin >> A[i];
  stack<long long> st;
  long long k;
  cin >> k;
  long long B[n];
  for (long long i = 0; i < n; i++) {
    B[i] = A[i];
  }
  for (long long i = 0; i < k; i++) {
    long long x;
    cin >> x;
    x--;
    B[x] = -B[x];
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (st.empty()) {
      st.push(A[i]);
      B[i] = -A[i];
    } else if (st.top() == B[i]) {
      st.pop();
    } else {
      st.push(A[i]);
      B[i] = -A[i];
    }
  }
  if (!st.empty()) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
    for (long long i = 0; i < n; i++) cout << B[i] << " ";
    cout << "\n";
  }
  return 0;
}
