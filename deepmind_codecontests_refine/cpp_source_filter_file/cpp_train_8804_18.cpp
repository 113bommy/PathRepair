#include <bits/stdc++.h>
using namespace std;
inline void scanf(int &n) {
  n = 0;
  char a = getchar();
  bool flag = 0;
  while (a < '0' || a > '9') {
    if (a == '-') flag = 1;
    a = getchar();
  }
  while ('0' <= a && a <= '9') {
    n = n * 10 + a - '0';
    a = getchar();
  }
  if (flag) n = -n;
}
const int MAXN = 1e5 + 10;
int n;
class Hanoi {
 public:
  int a, b, h;
  friend bool operator<(const Hanoi &a, const Hanoi b) {
    if (a.b != b.b)
      return a.b < b.b;
    else
      return a.a < b.a;
  }
} hanoi[MAXN];
int main() {
  scanf(n);
  for (int i = 0; i < n; i++) {
    int a, b, h;
    scanf(a);
    scanf(b);
    scanf(h);
    hanoi[i] = {a, b, h};
  }
  sort(hanoi, hanoi + n);
  long long int ans = 0;
  long long int height = 0;
  stack<Hanoi> stk;
  for (int i = n - 1; i >= 0; i--) {
    if (stk.empty()) {
      stk.push(hanoi[i]);
      height += hanoi[i].h;
      ans = max(ans, (long long)hanoi[i].h);
    } else {
      Hanoi top = stk.top();
      while (top.a > hanoi[i].b) {
        stk.pop();
        height -= top.h;
        if (stk.empty()) break;
        top = stk.top();
      }
      stk.push(hanoi[i]);
      height += hanoi[i].h;
      ans = max(ans, height);
    }
  }
  cout << ans << endl;
}
