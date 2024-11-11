#include <bits/stdc++.h>
using namespace std;
inline int isLucky(int x) { return x == 4 || x == 7; }
int countLucky(long long x) {
  int ret = 0;
  while (x) {
    int d = x % 10;
    ret += isLucky(d);
    x /= 10;
  }
  return ret;
}
int getLen(long long x) {
  int l = 0;
  while (x) x /= 10, l++;
  return l;
}
bool check(long long cur, int cnt, int rest, long long suffix,
           long long suffixPow, long long min) {
  if (cnt < 0 || cnt > rest) return false;
  for (int j = 0; j < rest - cnt; ++j) {
    cur = cur * 10 + 9;
  }
  for (int j = 0; j < cnt; ++j) {
    cur = cur * 10 + 7;
  }
  cur = cur * suffixPow + suffix;
  return cur > min;
}
long long buildMin(int cnt, long long suffix, int suffixLen, long long min) {
  long long suffixPow = 1;
  for (int j = 0; j < suffixLen; ++j) {
    suffixPow *= 10;
  }
  int cntCopy = cnt;
  for (int len = 0;; ++len) {
    long long cur = 0;
    cnt = cntCopy;
    if (!check(cur, cnt, len, suffix, suffixPow, min)) continue;
    for (int j = 0; j < len; ++j) {
      for (int digit = 0; digit < 10; ++digit) {
        int ncnt = cnt - isLucky(digit);
        long long ncur = cur * 10 + digit;
        if (check(ncur, ncnt, len - 1 - j, suffix, suffixPow, min)) {
          cur = ncur, cnt = ncnt;
          break;
        }
      }
    }
    return cur * suffixPow + suffix;
  }
  return -1;
}
long long doit(long long a, long long b) {
  long long l = b - a + 1;
  if (l >= 10) return doit(a / 10, b / 10) * 10 + a % 10;
  int cnt[10] = {};
  for (int i = 0; i < l; ++i) {
    cnt[i] = countLucky(a + i);
  }
  for (int i = a + 1; i < 10000; ++i) {
    bool check = true;
    for (int j = 0; j < l; ++j) {
      if (countLucky(i + j) != cnt[j]) {
        check = false;
        break;
      }
    }
    if (check) return i;
  }
  long long ans = LONG_LONG_MAX;
  for (int y = 0; y < 10; ++y) {
    for (int z = 0; z < 10; ++z) {
      for (int n9 = 0; n9 < 15; ++n9) {
        for (int x = 0; x < 9; ++x) {
          int num = isLucky(x) + isLucky(y) + isLucky(z);
          int need = cnt[0] - num;
          if (need < 0) continue;
          long long suffix = x;
          for (int j = 0; j < n9; ++j) {
            suffix = suffix * 10 + 9;
          }
          suffix = suffix * 10 + y;
          suffix = suffix * 10 + z;
          int suffixLen = 3 + n9;
          bool check = true;
          for (int j = 0; j < l; ++j) {
            int me = need + countLucky(suffix);
            if (me != cnt[j]) {
              check = false;
              break;
            }
          }
          if (!check) continue;
          if (buildMin(need, suffix, suffixLen, a) < a) {
            cout << need << " " << suffix << " " << suffixLen << endl;
          }
          ans = min(ans, buildMin(need, suffix, suffixLen, a));
        }
      }
    }
  }
  return ans;
}
int main() {
  long long a, l;
  cin >> a >> l;
  cout << doit(a, a + l - 1) << endl;
  return 0;
}
