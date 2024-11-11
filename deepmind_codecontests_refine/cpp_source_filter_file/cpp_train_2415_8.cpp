#include <bits/stdc++.h>
using namespace std;
const int n = 1e6 + 9;
int p[n];
int main() {
  long long ln;
  cin >> ln;
  if (ln == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (ln == 2) {
    cout << 2 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) p[i] = 1;
  p[0] = p[1] = 0;
  int flag1 = 0;
  for (int i = 2; i <= n; i++) {
    if (p[i] == 1) {
      for (int j = i * 2; j <= n; j += i) p[j] = 0;
    }
  }
  for (int i = 2; i <= sqrt(ln); i++) {
    if (ln % i == 0) {
      flag1 = 1;
      break;
    }
  }
  if (!flag1) {
    cout << ln << endl;
  } else {
    long long res;
    int flag = 0;
    for (long long i = 2; i <= sqrt(ln); i++) {
      if (p[i]) {
        long long sum = i;
        while (1) {
          if (sum == ln) {
            flag = 1;
            res = i;
            break;
          }
          if (sum > ln) break;
          sum *= sum;
        }
        if (flag) break;
      }
    }
    if (flag) {
      cout << res << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
