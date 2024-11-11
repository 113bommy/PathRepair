#include <bits/stdc++.h>
using namespace std;
char s[100000];
int main() {
  scanf("%s", s);
  priority_queue<pair<int, int>> Q;
  int i, cnt = 0;
  long long ans = 0;
  for (i = 0; s[i]; i++) {
    if (s[i] == '(') {
      cnt++;
    } else if (s[i] == ')') {
      cnt--;
    } else {
      int a, b;
      scanf("%d%d", &a, &b);
      s[i] = ')';
      cnt--;
      ans += b;
      Q.push(make_pair(b - a, i));
    }
    if (cnt < 0) {
      if (Q.empty()) {
        break;
      }
      ans -= Q.top().first;
      s[Q.top().second] = '(';
      Q.pop();
      cnt += 2;
    }
  }
  if (cnt == 0) {
    printf("%lld\n", ans);
    printf("%s\n", s);
  } else {
    printf("-1\n");
  }
}
