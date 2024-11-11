#include <bits/stdc++.h>
using namespace std;
struct Node {
  char c;
  long long sum;
  bool operator<(const Node &others) const {
    if (sum > others.sum)
      return true;
    else if (sum < others.sum)
      return false;
    else if (sum == others.sum)
      return c > others.c;
  }
};
Node e;
map<Node, long long> has;
int alp[30], len;
long long ans = 0, sum[100010];
char str[100010];
int main() {
  for (int i = 0; i < 26; i++) {
    scanf("%d", &alp[i]);
  }
  scanf("%s", str);
  len = strlen(str);
  has.clear();
  sum[0] = alp[str[0] - 'a'];
  for (int i = 0; i < len - 1; i++) {
    if (str[i] == str[i + 1]) ans++;
  }
  for (int i = 1; i < len; i++) {
    sum[i] = sum[i - 1] + alp[str[i] - 'a'];
    e.c = str[i];
    e.sum = sum[i - 1];
    if (has[e]) ans += has[e];
    e.c = str[i - 1];
    if (!has[e]) {
      has[e] = 1;
    } else {
      has[e]++;
    }
  }
  cout << ans;
  return 0;
}
