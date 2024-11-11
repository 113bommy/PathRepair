#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = 1e18 + 10;
const int MAX = 30;
int n;
int a[MAX];
int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
void process() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int x = a[0];
  for (int i = 1; i < n; i++) x = gcd(x, a[i]);
  for (int i = x; i >= 1; i--)
    if (x % i == 0) {
      if (i & 1) {
        int last = -1, cnt = 0;
        string s;
        for (int j = 0; j < n; j++) {
          if ((a[j] / i) & 1) {
            cnt++;
            last = j;
          }
          for (int k = 0; k < a[j] / 2; k++) s += (char)(j + 'a');
        }
        if (cnt > 1) continue;
        if (last != -1) s += (char)(last + 'a');
        int ns = int(s.size());
        for (int j = ns - 1 - (cnt > 0); j >= 0; j--) s += s[j];
        cout << i << '\n';
        for (int j = 0; j < i; j++) cout << s;
        return;
      } else {
        string s[2];
        for (int j = 0; j < n; j++)
          for (int k = 0; k < a[j] / i; k++) s[0] += (char)(j + 'a');
        for (int j = n - 1; j >= 0; j--)
          for (int k = 0; k < a[j] / i; k++) s[1] += (char)(j + 'a');
        cout << i << '\n';
        for (int j = 0; j < i; j++) cout << s[j & 1];
        return;
      }
    }
  cout << 0 << '\n';
  for (int i = 0; i < n; i++)
    for (int j = 0; j < a[i]; j++) cout << (char)(i + 'a');
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
