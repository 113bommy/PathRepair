#include <bits/stdc++.h>
using namespace std;
long long r, h;
void input() { cin >> r >> h; }
void process() {
  long long ans = 0;
  ans += (h / r) * (long long)2;
  if (h % r > (double)sin(3.14 / 6.0) * (double)r) {
    ans += 2;
    if ((h % r) * 2 >= r) ans++;
  } else
    ans++;
  cout << ans;
}
int main() {
  input();
  process();
  return 0;
}
