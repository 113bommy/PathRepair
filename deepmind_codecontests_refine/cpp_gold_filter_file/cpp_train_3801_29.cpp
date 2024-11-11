#include <bits/stdc++.h>
const double EPS = 1e-10;
using namespace std;
inline int rit() {
  int f = 0, key = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') key = -1;
  } while (c < '0' || c > '9');
  do {
    f = f * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return f * key;
}
vector<pair<long long, long long> > ans;
const int Z = 100005;
long long n;
int calc(long long x) {
  long long f = x * (x + 1) * (x * 2 + 1) / 6, f2 = x * (x + 1) / 2, fff;
  if (f > n) return 0;
  fff = (n - f) / f2;
  if ((n - f) % f2 == 0) ans.push_back(make_pair(x, x + fff));
  return 1;
}
void read() {
  long long i;
  scanf("%I64d", &n);
  for (i = 1; i <= 3000000; i++) {
    if (!calc(i)) break;
  }
  sort(ans.begin(), ans.end());
  if (ans.size() == 0) {
    cout << 0 << endl;
  } else {
    printf(
        "%I64d\n",
        ans.size() * 2 -
            (ans[ans.size() - 1].first == ans[ans.size() - 1].second ? 1 : 0));
    for (i = 0; i < ans.size(); i++) {
      printf("%I64d %I64d\n", ans[i].first, ans[i].second);
    }
    if (ans[i - 1].first == ans[i - 1].second) i--;
    for (i--; i >= 0; i--) {
      printf("%I64d %I64d\n", ans[i].second, ans[i].first);
    }
  }
}
int main() {
  read();
  return 0;
}
