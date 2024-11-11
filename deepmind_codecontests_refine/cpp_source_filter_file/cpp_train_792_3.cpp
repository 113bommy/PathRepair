#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T gcd(T a, T b) {
  return a == 0 ? b : gcd(b % a, a);
}
template <class T>
inline int countbit(T n) {
  return n == 0 ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline void pout(T A[], int n) {
  cout << "{";
  for (int i = 0; i < n; i++) cout << A[i] << ", ";
  cout << "}\n";
}
template <class T>
inline void pout(vector<T> A, int n = -1) {
  if (n == -1) n = A.size();
  cout << "{";
  for (int i = 0; i < n; i++) cout << A[i] << ", ";
  cout << "}\n";
}
bool a[100][100];
int main() {
  int i, j, k, n, m;
  string ss[100], ans;
  cin >> n >> m;
  for (i = 0; i < (n); ++i) cin >> ss[i];
  for (i = 0; i < (n); ++i)
    for (j = 0; j < (m); ++j) {
      if (a[i][j]) continue;
      char c = ss[i][j];
      for (k = 0; k < (n); ++k)
        if (k != j && ss[i][k] == c) a[i][k] = a[i][j] = true;
      for (k = 0; k < (m); ++k)
        if (k != i && ss[k][j] == c) a[k][j] = a[i][j] = true;
      if (!a[i][j]) ans += c;
    }
  cout << ans << endl;
  return 0;
}
