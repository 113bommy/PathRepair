#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n, d;
  cin >> n >> a >> b >> c >> d;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int s = i + a + b;
    int s1 = s - a - c;
    int s2 = s - b - d;
    int s3 = s - c - d;
    if (s1 >= 1 && s1 <= n) {
      if (s2 >= 1 && s2 <= n) {
        if (s3 >= 1 && s3 <= n) {
          res++;
        }
      }
    }
  }
  cout << res * n << endl;
  return 0;
}
