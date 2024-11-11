#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> v;
  v.push_back(+1);
  for (;;) {
    char c;
    scanf(" %c", &c);
    if (c == '=') break;
    if (c == '+')
      v.push_back(+1);
    else if (c == '-')
      v.push_back(-1);
  }
  scanf("%d", &n);
  int ans = 0;
  for (auto x : v)
    if (x == +1)
      ans += n;
    else
      ans -= 1;
  if (ans < n) {
    puts("Impossible");
    return 0;
  }
  vector<int> p;
  for (auto x : v) {
    if (x == +1 and ans > n) {
      int mn = min(ans - n, n - 1);
      p.push_back(n - mn);
      ans -= mn;
    } else if (x == -1 and ans > n) {
      int mn = min(ans - n, n - 1);
      p.push_back(mn + 1);
      ans -= mn;
    } else {
      p.push_back(x == +1 ? n : 1);
    }
  }
  if (ans != n) {
    puts("Impossible");
    return 0;
  }
  puts("Possible");
  printf("%d ", p[0]);
  for (int i = 1; i < p.size(); i++) {
    printf("%c %d ", (v[i] == +1 ? '+' : '-'), p[i]);
  }
  printf("= %d\n", n);
  return 0;
}
