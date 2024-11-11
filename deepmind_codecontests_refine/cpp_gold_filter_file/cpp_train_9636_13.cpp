#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
long long A[200004], B[200004];
vector<long long> V;
int main() {
  long long n = getnum(), r = getnum();
  for (int i = 1; i <= n; i++) A[i] = getnum();
  for (int i = 1; i <= n; i++) {
    B[i] = getnum();
    if (A[i] > B[i]) {
      puts("-1");
      return 0;
    }
  }
  long long juice = 0, tim = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (juice >= A[i]) {
      juice -= A[i];
      tim += A[i];
    } else {
      long long rem = A[i] - juice, tot = B[i] - juice;
      tim += juice;
      if (tot < rem * 2) {
        long long x = tot - rem, req = 0;
        tim += x * 2;
        x = rem - x;
        req = x / r;
        juice = r - x % r;
        if (x % r > 0)
          req++;
        else
          juice = 0;
        long long temp = ans, ctim = tim;
        ans += req;
        tim += x;
        for (int j = 1; j <= req && temp <= 100000; j++, temp++, ctim += r)
          V.push_back(ctim);
      } else {
        tim += rem * 2;
        juice = 0;
      }
    }
  }
  printf("%lld\n", ans);
  for (int i = 0; i < V.size() && ans <= 100000; i++) printf("%lld ", V[i]);
}
