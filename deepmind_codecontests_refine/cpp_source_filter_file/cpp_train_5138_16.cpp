#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
const int inf = 0x3f3f3f3f;
const int Max = 200000;
template <class T>
inline void getin(T& num) {
  char c;
  bool flag = 0;
  num = 0;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = 1;
  while (c >= '0' && c <= '9') {
    num = num * 10 + c - 48;
    c = getchar();
  }
  if (flag) num = -num;
}
int n, k, a, x, y, m;
queue<int> num[N];
set<pair<int, int> > output;
vector<pair<int, int> > Ans;
int main() {
  getin(n);
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    getin(k), getin(a), sum += k;
    getin(x), getin(y), getin(m);
    num[i].push(a);
    int ret = 0;
    for (int j = 2; j <= k; j++) {
      int nxt = (1ll * a * x % m + y) % m;
      if (nxt > a) ret++;
      num[i].push(a = nxt);
    }
    ans = max(ans, ret);
  }
  printf("%d\n", ans);
  if (sum > Max) return 0;
  for (int i = 1; i <= n; i++) {
    output.insert(make_pair(num[i].front(), i));
    num[i].pop();
  }
  int last = -inf, p;
  for (int i = 1; i <= sum; i++) {
    set<pair<int, int> >::iterator it =
        output.lower_bound(make_pair(last, -inf));
    if (it == output.end()) ans++, it = output.begin();
    Ans.push_back(*it);
    last = (*it).first;
    p = (*it).second;
    output.erase(it);
    if (!num[p].empty()) {
      output.insert(make_pair(num[p].front(), p));
      num[p].pop();
    }
  }
  for (int i = 0; i < sum; i++) printf("%d %d\n", Ans[i].first, Ans[i].second);
}
