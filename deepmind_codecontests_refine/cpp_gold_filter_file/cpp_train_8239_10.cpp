#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long a[11111];
int main() {
  int n = read();
  long long tt = 0;
  for (int i = 1; i <= n; i++) a[i] = read(), tt += a[i];
  long long tot = a[1];
  vector<int> ans;
  ans.push_back(1);
  for (int i = 2; i <= n; i++)
    if (a[1] >= 2 * a[i]) {
      tot += a[i];
      ans.push_back(i);
    }
  if (tot * 2 > tt) {
    cout << ((ans).size()) << endl;
    int sz = ((ans).size());
    for (int i = 0; i < sz; i++) {
      if (i) cout << ' ';
      cout << ans[i];
    }
    return 0;
  }
  puts("0");
  return 0;
}
