#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, d, maxx = -1000000000000000, minn = 100000000000000000,
                           ans1, ans2, ans3, ans4, ans = 0, a1;
  cin >> n >> a >> b >> c >> d;
  maxx = max(maxx, a + b);
  maxx = max(maxx, a + c);
  maxx = max(maxx, d + b);
  maxx = max(maxx, d + c);
  minn = min(minn, a + b);
  minn = min(minn, a + c);
  minn = min(minn, d + b);
  minn = min(minn, d + c);
  if ((maxx + 1) - minn > n) {
    cout << "0" << endl;
    return 0;
  }
  ans1 = maxx - (a + b);
  if (ans1 == 0)
    ans1 = 1;
  else
    ans1++;
  ans2 = maxx - (a + c);
  if (ans2 == 0)
    ans2 = 1;
  else
    ans2++;
  ans3 = maxx - (d + b);
  if (ans3 == 0)
    ans3 = 1;
  else
    ans3++;
  ans4 = maxx - (d + c);
  if (ans4 == 0)
    ans4 = 1;
  else
    ans4++;
  ans += n;
  if (ans1 == n || ans2 == n || ans3 == n || ans4 == n) {
    cout << ans << endl;
    return 0;
  } else {
    a1 = max(ans1, ans2);
    a1 = max(a1, ans3);
    a1 = max(a1, ans4);
    a1 = n - a1;
    ans += n * a1;
    cout << ans << endl;
  }
  return 0;
}
