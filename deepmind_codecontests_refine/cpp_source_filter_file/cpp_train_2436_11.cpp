#include <bits/stdc++.h>
using namespace std;
int a, b;
pair<int, int> vec;
char s[101];
vector<pair<int, int> > coord;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d %d\n", &a, &b);
  gets(s);
  int n = strlen(s);
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (x == a && y == b) return !printf("Yes\n");
    coord.push_back(make_pair(x, y));
    if (s[i] == 'U') ++y;
    if (s[i] == 'D') --y;
    if (s[i] == 'R') ++x;
    if (s[i] == 'L') --x;
  }
  vec.first = x;
  vec.second = y;
  if (!x && !y) {
    return !printf("No\n");
  }
  for (int i = 0; i < coord.size(); ++i) {
    if ((vec.second * 1ll * (a - coord[i].first) ==
         vec.first * 1ll * (b - coord[i].second)) &&
        vec.first * 1ll * (a - coord[i].first) >= 0 &&
        vec.second * 1ll * (b - coord[i].second) >= 0)
      if (x) {
        if (1ll * (a - coord[i].first) % vec.first == 0)
          return !printf("Yes\n");
      } else if (1ll * (a - coord[i].first) % vec.second == 0)
        return !printf("Yes\n");
  }
  puts("No");
  return 0;
}
