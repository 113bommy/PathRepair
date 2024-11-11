#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int maxar(int arr[], int n) {
  int res = arr[0];
  for (int i = 0; i < n; i++) {
    res = max(res, arr[i]);
  }
  return res;
}
long long maxar(long long arr[], long long n) {
  long long res = arr[0];
  for (long long i = 0; i < n; i++) {
    res = max(res, arr[i]);
  }
  return res;
}
long long minar(long long arr[], long long n) {
  long long res = arr[0];
  for (long long i = 0; i < n; i++) {
    res = min(res, arr[i]);
  }
  return res;
}
int minar(int arr[], int n) {
  int res = arr[0];
  for (int i = 0; i < n; i++) {
    res = min(res, arr[i]);
  }
  return res;
}
void inpar(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
void inpar(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
void solve() {
  int n = readInt<int>();
  int k = readInt<int>();
  if (k > n) {
    cout << -1;
    return;
  }
  char arr[27] = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                  'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                  'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  if (k == 1 && n > 1) {
    cout << -1;
    return;
  }
  if (k == 1 && n == 1) {
    cout << 'a';
    return;
  }
  if (k == 2 && n == 2) {
    cout << 'ab';
    return;
  }
  string res;
  bool f1 = true;
  while (res.size() < n - (k - 2)) {
    if (f1)
      res += 'a', f1 = false;
    else
      res += 'b', f1 = true;
  }
  int pos = 3;
  while (res.size() != n) {
    if (pos == 27) {
      cout << -1;
      return;
    }
    res += arr[pos++];
  }
  cout << res;
}
int32_t main() {
  int tc;
  tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
