#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
template <class T>
int size(const T &x) {
  return x.size();
}
long long base = 256;
long long mod = 2147483549;
const int N = 5000010;
char s[N];
int arr[N], arr2[N], pm[N], deg[N];
int main() {
  scanf("%s\n", s);
  int n = strlen(s);
  pm[0] = 1;
  for (int i = 1; i <= n; i++) {
    pm[i] = ((long long)pm[i - 1] * base) % mod;
  }
  arr[0] = arr2[0] = 0;
  for (int i = 0; i < n; i++) {
    arr[i + 1] = ((long long)arr[i] * base + s[i]) % mod;
    arr2[i + 1] = ((long long)arr2[i] * base + s[n - i - 1]) % mod;
  }
  deg[0] = 0;
  long long sm = 1;
  deg[1] = 1;
  for (int i = 2; i <= n; i++) {
    int j = i / 2;
    if (((arr[(j - 1) + 1] -
          ((long long)arr[(0)] * pm[(j - 1) - (0) + 1]) % mod + mod) %
         mod) ==
        ((arr2[(n - (i - j) - 1) + 1] -
          ((long long)arr2[(n - (i - 1) - 1)] * pm[(i - 1) - (i - j) + 1]) %
              mod +
          mod) %
         mod)) {
      deg[i] = deg[j] + 1;
    } else {
      deg[i] = 0;
    }
    sm += deg[i];
  }
  cout << sm << endl;
  return 0;
}
