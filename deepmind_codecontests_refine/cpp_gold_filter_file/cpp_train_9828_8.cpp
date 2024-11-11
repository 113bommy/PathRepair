#include <bits/stdc++.h>
using namespace std;
int Read() {
  char c;
  while (c = getchar(), (c != '-') && (c < '0' || c > '9'))
    ;
  bool neg = (c == '-');
  int ret = (neg ? 0 : c - 48);
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
  return neg ? -ret : ret;
}
multiset<int> t;
map<int, int> a;
int N, b[500005];
long long ans;
int main() {
  scanf("%d", &N);
  for (; N; N--) {
    int x = Read();
    ++a[x], ans += x;
  }
  for (map<int, int>::reverse_iterator it = a.rbegin(); it != a.rend(); it++) {
    int x = it->first, y = it->second, ms = min(N, (N + y) / 2),
        from = max(0, ms - y);
    for (int i = ms - 1; i >= from; i--)
      if (i < t.size())
        b[i] = *t.begin(), t.erase(t.begin());
      else
        b[i] = 0;
    for (int i = from, j = N - i; i < j && i < ms; i++)
      if (b[i] < x)
        b[i] = x;
      else if (--j < ms)
        b[j] = max(0, 2 * x - b[i]);
    t.insert(b + from, b + ms), N += y;
  }
  cout << ans - accumulate(t.begin(), t.end(), 0LL) << endl;
  return 0;
}
