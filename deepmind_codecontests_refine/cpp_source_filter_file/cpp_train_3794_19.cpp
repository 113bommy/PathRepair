#include <bits/stdc++.h>
using namespace std;
inline int readInt() {
  register int c = getchar();
  int x = 0;
  for (; (c < 48 || c > 57); c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) {
    x = x * 10 + c - 48;
  }
  return x;
}
long long C[70][70];
int k;
void initC() {
  for (int i = 0; i < int(70); i++)
    for (int j = 0; j < int(70); j++) C[i][j] = 0;
  for (int i = 0; i < int(70); i++) {
    C[i][i] = 1;
    C[i][0] = 1;
  }
  for (int i = 1; i < 70; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}
long long obj(long long n) {
  vector<bool> bin;
  while (n > 0) {
    bin.push_back(n % 2);
    n /= 2;
  }
  int m = bin.size() - 1;
  int c = k;
  long long ret = 0;
  while (m >= 0 && c > 0) {
    if (bin[m]) {
      ret += C[m][c - 1];
      c--;
    }
    m--;
  }
  return ret;
}
int main() {
  initC();
  long long m;
  cin >> m >> k;
  long long nh = 1e18;
  long long nl = 0;
  long long mid = (nh + nl) / 2;
  long long ret = 0;
  while (nh >= nl) {
    long long x = obj(mid);
    if (x == m) {
      ret = mid;
      break;
    } else if (x > m) {
      nh = mid - 1;
      mid = (nl + nh) / 2;
    } else {
      nl = mid + 1;
      mid = (nl + nh) / 2;
    }
  }
  cout << ret;
  return 0;
}
