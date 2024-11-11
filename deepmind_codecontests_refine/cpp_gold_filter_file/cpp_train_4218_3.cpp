#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void smax(T &x, T y) {
  x = max((x), (y));
}
template <class T>
inline void smin(T &x, T y) {
  x = min((x), (y));
}
const int MOD = 1e9 + 7;
const int SIZE = 2 * 1e3 + 10;
const int INF = 0x3f3f3f3f;
long long x, y;
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  return a == 0 ? b : gcd(b % a, a);
}
void go(long long ora, long long app, string &ans) {
  if (ora == app && ora == 1) return;
  long long num;
  stringstream ss;
  string str;
  if (ora == 1) {
    num = app / ora - 1;
    ss << num << 'B';
    ss >> str;
    ans.append(str);
    return;
  }
  if (app == 1) {
    num = ora / app - 1;
    ss << num << 'A';
    ss >> str;
    ans.append(str);
    return;
  }
  if (ora > app) {
    num = ora / app;
    ss << num << 'A';
    ss >> str;
    ans.append(str);
    go(ora % app, app, ans);
  } else {
    num = app / ora;
    ss << num << 'B';
    ss >> str;
    ans.append(str);
    go(ora, app % ora, ans);
  }
}
int main() {
  if (0) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  while (scanf("%I64d%I64d", &x, &y) == 2) {
    if (gcd(x, y) > 1) {
      printf("Impossible\n");
      continue;
    }
    string ans;
    go(x, y, ans);
    printf("%s\n", ans.c_str());
  }
  return 0;
}
