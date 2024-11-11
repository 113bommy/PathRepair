#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int N = 2 * 5000000;
bool isexist[N + 1] = {false};
long long solve(long long b, long long c) {
  long long ret = 0;
  long long tmp1 = (long long)sqrt(b * b - 1),
            tmp2 = (long long)sqrt(b * b - min(b * b, c));
  ret = 2 * (min(b * b - 1, c) - (tmp1 - tmp2));
  long long cnt = (long long)floor(sqrt(b * b - 1)) -
                  (long long)ceil(sqrt(b * b - min(b * b, c + 1)));
  if (c >= b * b) {
    if (!isexist[N - b]) ret++;
    isexist[N - b] = true;
  }
  long long l = (long long)ceil(sqrt(b * b - min(b * b, c))),
            r = (long long)floor(sqrt(b * b - 1));
  for (int i = l; i < r + 1; i++) {
    if (!isexist[N + -b + i]) ret++;
    isexist[N + -b + i] = true;
    if (!isexist[N + -b - i]) ret++;
    isexist[N + -b - i] = true;
  }
  return ret;
}
int main() {
  long long b, c;
  long long ans = 0;
  cin >> b >> c;
  for (int i = 0; i < N + 1; i++) isexist[i] = false;
  for (int i = 1; i < b + 1; i++) {
    ans += solve(i, c);
  }
  cout << ans << endl;
  return false;
}
