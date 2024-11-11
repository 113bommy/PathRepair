#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
template <class T>
inline T min(T a, T b, T c) {
  return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c) {
  return max(max(a, b), c);
}
template <class T>
inline T min(T a, T b, T c, T d) {
  return min(min(a, b), min(c, d));
}
template <class T>
inline T max(T a, T b, T c, T d) {
  return max(max(a, b), max(c, d));
}
using namespace std;
const int N = 1e3 + 7;
typedef int arr[N];
typedef long long aLL[N];
const double eps = 1e-9;
long long mod = 1e9 + 7;
int n;
char s[N];
arr a, f;
long long ans1 = 0, ans2 = 0, ans3 = 0;
int main() {
  scanf("%d", &n);
  getchar();
  scanf("%s", s + 1);
  getchar();
  for (int i = 0; i <= 25; i++) scanf("%d", &a[i]);
  f[1] = 1, f[0] = 1;
  for (int i = 2; i <= n; i++) {
    int mi = a[s[i] - 'a'];
    for (int j = i; j >= 1; j--) {
      (mi) = (mi) <= (a[s[j] - 'a']) ? (mi) : (a[s[j] - 'a']);
      if (i - j + 1 <= mi)
        (f[i]) = ((f[i]) % mod + (f[j - 1]) % mod) % mod,
        (ans2) = (ans2) >= (i - j + 1) ? (ans2) : (i - j + 1);
      else
        break;
    }
  }
  ans1 = f[n];
  ans3 = 1;
  int sum = 0, mi = a[s[1] - 'a'], len = 0;
  for (int i = 1; i <= n; i++) {
    (mi) = (mi) <= (a[s[i] - 'a']) ? (mi) : (a[s[i] - 'a']);
    if (len + 1 <= mi)
      len++;
    else
      ans3++, len = 1, mi = a[s[i] - 'a'];
  }
  cout << ans1 << endl << ans2 << endl << ans3 << endl;
  return 0;
}
