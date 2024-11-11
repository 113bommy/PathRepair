#include <bits/stdc++.h>
using namespace std;
void freac() {}
const int DX[] = {+1, 0, -1, 0, +1, +1, -1, -1};
const int DY[] = {0, +1, 0, -1, +1, -1, +1, -1};
const int INF = (int)1e9 + 123;
const long long INFL = (long long)1e18 + 123;
const double EPS = 1e-9;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
void lifestyle() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
int main() {
  lifestyle();
  freac();
  long long a, b, k;
  cin >> k >> a >> b;
  if (b <= 0) {
    a = -a;
    b = -b;
    swap(a, b);
  }
  long long cnt = b / k - a / k;
  if (a % k == 0 || a < 0) {
    cnt++;
  }
  cout << cnt << endl;
  return false;
}
