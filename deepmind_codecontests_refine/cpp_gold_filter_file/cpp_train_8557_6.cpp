#include <bits/stdc++.h>
using namespace std;
template <typename IntType>
void read(IntType& val) {
  val = 0;
  int c;
  bool inv = false;
  while (!isdigit(c = getchar()))
    if (c == '-') inv = true;
  do {
    val = (val << 1) + (val << 3) + c - '0';
  } while (isdigit(c = getchar()));
  if (inv) val = -val;
}
template <>
void read<string>(string& str) {
  str.clear();
  int c;
  while (iscntrl(c = getchar()) || c == ' ' || c == '\t')
    ;
  do {
    str.push_back(c);
  } while (!(iscntrl(c = getchar()) || c == ' ' || c == '\t'));
}
long long k, n;
long long getcnt(long long x) {
  long long ans = 0;
  for (int i = (0); i <= (62); ++i) {
    long long l = x << i, r;
    if (x & 1)
      r = l + (1ll << i) - 1;
    else
      r = l + (1ll << (i + 1)) - 1;
    if (l > n)
      break;
    else if (r <= n)
      ans += (r - l + 1);
    else
      ans += n - l + 1;
  }
  return ans;
}
bool check(long long x) { return getcnt(x) >= k; }
long long ans = 0;
void odd() {
  long long l = 1, r;
  if (n & 1)
    r = n / 2 + 1;
  else
    r = n / 2;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (check(mid * 2 - 1))
      l = mid;
    else
      r = mid;
  }
  if (check(r * 2 - 1))
    ans = max(ans, r * 2 - 1);
  else if (check(l * 2 - 1))
    ans = max(ans, l * 2 - 1);
}
void even() {
  long long l = 1, r = n / 2;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (check(mid * 2))
      l = mid;
    else
      r = mid;
  }
  if (check(r * 2))
    ans = max(ans, r * 2);
  else if (check(l * 2))
    ans = max(ans, l * 2);
}
int main(int argc, char* argv[]) {
  read(n);
  read(k);
  even();
  odd();
  cout << ans << endl;
  return 0;
}
