#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
const int N = 1 << 18;
int a[N];
int main() {
  int n, f = 1;
  cin >> n;
  for (int i = 1; i < n + 1; ++i) {
    cin >> a[i];
    if (a[i] == -1) {
      a[i] = 0;
      f = 0;
    } else if (f)
      a[i] = 0;
  }
  priority_queue<int, vector<int>, greater<int>> que;
  int pow = n, ans = 0;
  for (int i = n; i >= 1; --i) {
    que.push(a[i]);
    if (pow == i) {
      pow /= 2;
      ans += que.top();
      que.pop();
    }
  }
  cout << ans << '\n';
}
