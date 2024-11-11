#include <bits/stdc++.h>
using namespace std;
int p[205] = {0};
int q[205] = {0};
int ti = 1;
long long gcd(long long x, long long y) {
  while (1) {
    long long t = x % y;
    if (t == 0) break;
    x = y;
    y = t;
  }
  return y;
}
int main() {
  int n, i, j;
  long long answer = 1;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> p[i];
  for (i = 1; i <= n; i++) {
    int temp = i;
    for (j = 1;; j++) {
      temp = p[temp];
      if (q[temp] != 0) {
        int tmp = j - q[temp];
        answer = answer / gcd(answer, tmp) * tmp;
        if (q[temp] > ti) ti = q[temp];
        break;
      }
      q[temp] = j;
    }
    for (j = 1; j <= n; j++) q[j] = 0;
  }
  answer *= (ti - 1) / answer + 1;
  cout << answer << endl;
  return 0;
}
