#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 50;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
int x[maxn];
int y[maxn];
void who(string s, int i) {
  char top = s[0];
  if (top == 'B')
    x[i] = 0;
  else if (top == 'Y')
    x[i] = 1;
  else if (top == 'W')
    x[i] = 2;
  else if (top == 'G')
    x[i] = 3;
  else
    x[i] = 4;
  y[i] = s[1] - '1';
}
int n;
int bit(int i) { return 1 << i; }
bool check(int sta) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (x[i] == x[j]) {
        if (y[i] != y[i] && (sta & bit(y[i] + 5)) == 0 &&
            (sta & bit(y[j] + 5)) == 0)
          return false;
      } else {
        if ((sta & bit(x[i])) || (sta & bit(x[j]))) continue;
        if (y[i] != y[j] && ((sta & bit(y[i] + 5)) || (sta & bit(y[j] + 5))))
          continue;
        return false;
      }
    }
  }
  return true;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    who(s, i);
  }
  int ans = inf;
  for (int sta = 0; sta < (1 << 10); sta++) {
    int num = 0;
    for (int i = 0; i < 5; i++) {
      if (sta & (1 << i)) {
        num++;
      }
      if (sta & (1 << (i + 5))) {
        num++;
      }
    }
    if (check(sta)) ans = min(ans, num);
  }
  cout << ans << endl;
  return 0;
}
