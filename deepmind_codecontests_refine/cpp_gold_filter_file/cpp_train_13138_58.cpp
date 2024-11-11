#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 44;
const int mod = 1e9 + 9, b = 123458;
long long rcshnt[MN];
int n;
char a[MN];
bool check(int len) {
  ;
  long long curr = 0;
  for (int i = 0; i < len; ++i) curr = (curr * b + a[i]) % mod;
  long long pre = curr;
  ;
  for (int i = len; i < n - 1; ++i) {
    ;
    ;
    curr = ((curr - a[i - len] * rcshnt[len - 1]) % mod * b + a[i]) % mod;
    ;
    if ((pre - curr) % mod == 0) {
      ;
      return true;
    }
  };
  return false;
}
int main() {
  scanf("%s", a);
  n = strlen(a);
  rcshnt[0] = 1;
  for (int i = 1; i < MN; ++i) {
    rcshnt[i] = rcshnt[i - 1] * b % mod;
  }
  for (int i = 0; i < 10; ++i)
    ;
  vector<int> pre;
  long long ph = 0, sh = 0;
  for (int i = 0; i < n - 1; ++i) {
    ph = (ph * b + a[i]) % mod;
    sh = (sh + a[n - i - 1] * rcshnt[i]) % mod;
    if (ph == sh) {
      pre.push_back(i + 1);
      ;
    }
  }
  int low = 1, high = n - 1, ans = 0;
  while (low <= high) {
    int med = (low + high) / 2;
    if (check(med)) {
      ans = med;
      low = med + 1;
    } else
      high = med - 1;
  }
  int res = -1;
  for (auto c : pre) {
    if (c <= ans) res = max(res, c);
  }
  if (res <= 0) {
    printf("Just a legend\n");
  } else {
    a[res] = 0;
    printf("%s\n", a);
  }
}
