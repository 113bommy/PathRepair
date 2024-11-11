#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const double INF = 1e12, EPS = 1e-9;
int n, a[100000];
long long s[100000];
void run() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = 30; j >= 0; j--)
      if (i & 1 << j) {
        s[k] += a[i];
        k -= 1 << j;
      }
  }
  for (int i = n - 1; i >= 0; i--) s[i] += s[i + 1];
  for (int i = 0; i < n - 1; i++) cout << s[n - i - 1] << endl;
}
int main() { run(); }
