#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> A(n + 1);
  cout << "? 1 2\n";
  fflush(stdout);
  cin >> A[1];
  cout << "? 2 3\n";
  fflush(stdout);
  cin >> A[2];
  cout << "? 1 3\n";
  fflush(stdout);
  cin >> A[3];
  A[1] = (A[3] + (A[1] - A[2])) / 2;
  A[3] -= A[1];
  A[2] -= A[3];
  for (int i = 4; i <= n; i++) {
    cout << "? 1 " << i << endl;
    fflush(stdout);
    cin >> A[i];
    A[i] -= A[1];
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << A[i] << " ";
  return 0;
}
