#include <bits/stdc++.h>
using namespace std;
long long c(long long x) { return x * x * x; }
long long m[19 + 1];
int main(int argc, char *argv[]) {
  long long M;
  cin >> M;
  long long cur = 1;
  long long i = 0;
  while (m[i] <= M && i < 19) {
    while (m[i] + c(cur) >= c(cur + 1)) cur++;
    m[i + 1] = m[i] + c(cur);
    i++;
  }
  --i;
  long long ans1 = i;
  cur = 100000;
  long long ans2 = 0;
  while (cur && i) {
    long long cc = c(cur);
    if (cc > M) {
      --cur;
      continue;
    }
    if (M - cc >= m[i - 1]) {
      ans2 += cc;
      M -= cc;
      --i;
    } else {
      M = cc - 1;
      --cur;
    }
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
