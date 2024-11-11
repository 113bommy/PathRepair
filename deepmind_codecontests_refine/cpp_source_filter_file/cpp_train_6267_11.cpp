#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long a[maxn], line[maxn];
int main() {
  long long tot = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tot += a[i];
  }
  int now = 0;
  long long answer = 0x7FFFFFFFFFFFFFFF;
  for (int k = tot; k >= 2; k--)
    if (tot % k == 0) {
      now = k;
      long long i = 0, fin = 1, answ = 0, ansm = 0, minn = 0x7FFFFFFFFFFFFFFF,
                ans = 0;
      while (i < tot / now) {
        ansm = 0;
        answ = 0;
        minn = 0x7FFFFFFFFFFFFFFF;
        long long get = 0;
        while (get < now) {
          while (a[fin] == 0) fin++;
          line[++get] = fin;
          answ += fin;
          fin++;
        }
        long long l = 0;
        long long r = get;
        for (long long i = line[1]; i <= line[get]; i++) {
          minn = min(minn, l * i - ansm + answ - r * i);
          if (i = line[l + 1]) {
            ansm += i;
            answ -= i;
            l++;
            r--;
          }
        }
        ans += minn;
        i++;
      }
      answer = min(ans, answer);
    }
  if (tot == 1) answer = -1;
  if (tot == 0) answer = 0;
  cout << answer << endl;
}
