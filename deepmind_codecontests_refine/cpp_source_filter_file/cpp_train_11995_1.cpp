#include <bits/stdc++.h>
using namespace std;
const int N = 103;
template <typename T>
void read(T &x) {
  int ch = getchar();
  bool f = false;
  x = 0;
  for (; ch < '0' || ch > '9'; ch = getchar()) f |= ch == '-';
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) return a = b, 1;
  return 0;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) return a = b, 1;
  return 0;
}
int n, a[N], b[N], c[N];
char ans[N];
void ask(int *a, int L, int R) {
  cout << "? " << L << " " << R << endl;
  int _ = (R - L + 1) * (R - L + 2) >> 1;
  string S;
  while (_--) {
    cin >> S;
    int l = S.size();
    for (char c : S) a[l] += c;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  if (n <= 3) {
    for (int i = 1; i <= 3; ++i) {
      cout << "? " << i << " " << i << endl;
      cin >> ans[i];
    }
    cout << "! " << ans + 1 << endl;
    return 0;
  }
  ask(a, 1, n >> 1);
  ask(b, 2, n >> 1);
  ask(c, 1, n);
  for (int i = 1; i <= (n >> 1); ++i) {
    a[i] -= b[i];
    ans[i] = a[i] - a[i - 1];
  }
  int lst = 0;
  if (n & 1) ans[n + 1 >> 1] = lst = c[n + 1 >> 1] - c[n >> 1];
  for (int i = n >> 1; i; --i) {
    ans[n + 1 - i] = c[i] - c[i - 1] - lst - ans[i];
    lst = c[i] - c[i - 1];
  }
  cout << "! " << ans + 1 << endl;
}
