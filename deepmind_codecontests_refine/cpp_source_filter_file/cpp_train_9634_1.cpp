#include <bits/stdc++.h>
using namespace std;
int limit[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int to7(int n, int *N) {
  vector<int> digits;
  int ret = 0;
  while (n > 0) {
    digits.push_back(n % 7);
    n /= 7;
  }
  for (int i = digits.size() - 1; i >= 0; i--) {
    ret = (ret * 10) + digits[i];
  }
  *N = max((int)digits.size(), 1);
  return ret;
}
bool isUnique(int num, int *m) {
  while (num > 0) {
    int digit = num % 10;
    if (digit > 6 || (*m & (1 << digit))) {
      return false;
    }
    *m |= (1 << digit);
    num /= 10;
  }
  return true;
}
int main() {
  int Case = 1;
  int n, m, k;
  char dump[2];
  while (scanf("%d %d", &n, &m) == 2) {
    n = n - 1;
    m = m - 1;
    int digitn = 0, digitm = 0, stn = 0, stm = 0;
    int lenn = to7(n, &digitn);
    int lenm = to7(m, &digitm);
    for (int i = 1; i < digitn; i++) {
      stn = (stn * 10) + i;
    }
    for (int i = 1; i < digitm; i++) {
      stm = (stm * 10) + i;
    }
    long long int ans = 0;
    if ((digitn + digitm) <= 6) {
      for (int i = stn; i <= lenn; i++) {
        int mark = 0;
        if (i < limit[digitn - 1]) {
          mark = mark | 1;
        }
        if (isUnique(i, &mark)) {
          for (int j = stm; j <= lenm; j++) {
            int tmpMark = mark;
            if (j < limit[digitm - 1]) {
              if (!(tmpMark & 1)) {
                tmpMark = tmpMark | 1;
                if (isUnique(j, &tmpMark)) {
                  ans++;
                }
              }
            } else {
              if (isUnique(j, &tmpMark)) {
                ans++;
              }
            }
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
