#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000ll;
long long a, b, ans;
int k;
vector<int> best, current;
void rec(long long x, long long res, bool empty) {
  if (x == b + 1) {
    if (empty) return;
    if (res < ans) {
      ans = res;
      best = current;
    }
    return;
  }
  if ((int)current.size() < k) {
    current.push_back(x);
    rec(x + 1, (res ^ x), 0);
    current.pop_back();
  }
  rec(x + 1, res, empty);
}
int main() {
  ans = INF;
  cin >> a >> b >> k;
  if (b - a <= 10) {
    rec(a, 0, 1);
    cout << ans << endl;
    cout << best.size() << endl;
    for (int i = 0; i < best.size(); i++) cout << best[i] << " ";
    return 0;
  }
  if (k == 1) {
    cout << a << endl;
    cout << 1 << endl;
    cout << a << endl;
    return 0;
  }
  if (k == 2) {
    cout << 1 << endl;
    if (a % 2 == 1) a++;
    cout << 2 << endl;
    cout << a << " " << a + 1;
    return 0;
  }
  if (k >= 4) {
    cout << 0 << endl;
    cout << 4 << endl;
    if (a % 2 == 1) a++;
    cout << a << " " << a + 1 << " " << a + 2 << " " << a + 3;
    return 0;
  }
  long long l = 1, r = 3;
  while (r <= b) {
    if (l >= a) {
      cout << 0 << endl;
      cout << 3 << endl;
      cout << l << " " << r - 1 << " " << r;
      return 0;
    }
    l *= 2;
    l++;
    r *= 2;
  }
  cout << 1 << endl;
  cout << 2 << endl;
  if (a % 2 == 1) a++;
  cout << a << " " << a + 1;
  return 0;
}
