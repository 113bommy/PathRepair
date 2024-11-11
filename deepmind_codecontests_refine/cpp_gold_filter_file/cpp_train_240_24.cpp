#include <bits/stdc++.h>
using namespace std;
long long A[114], B[114];
int op[114];
int cnt;
void PushIn(long long a, long long b) {
  ++cnt, A[cnt] = a, B[cnt] = b;
  if (b == 0) return void();
  PushIn(b, a % b);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    cnt = 0;
    PushIn(max(a, b), min(a, b));
    op[cnt] = 0;
    for (register int i = cnt - 1; i; --i)
      if (op[i + 1] == 0)
        op[i] = 1;
      else {
        long long tim = A[i] / B[i];
        if ((tim % (B[i] + 1)) & 1)
          op[i] = 0;
        else
          op[i] = 1;
      }
    if (op[1])
      puts("First");
    else
      puts("Second");
  }
  return 0;
}
