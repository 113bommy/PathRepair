#include <bits/stdc++.h>
using namespace std;
int h;
long long n;
int main() {
  cin >> h >> n;
  if (n == 1 && h == 1) {
    cout << 1;
    return 0;
  }
  long long res = 0;
  bool t = 1;
  long long g = 1;
  stack<int> dis;
  for (int i = 0; i < h; i++) {
    dis.push(n % 2);
    n = (n + 1) / 2;
    g *= 2;
  }
  int d;
  for (int i = 0; i < h; i++) {
    d = dis.top();
    dis.pop();
    if (t != d) {
      res += g;
    } else {
      res += 1;
    }
    g /= 2;
    t = !d;
  }
  cout << res;
  return 0;
}
