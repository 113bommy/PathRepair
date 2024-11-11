#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace _buff {
const size_t BUFF = 1 << 19;
char buff[BUFF], *begin = buff, *end = buff;
char getc() {
  if (begin == end) {
    begin = buff;
    end = buff + fread(buff, 1, BUFF, stdin);
  }
  return begin == end ? -1 : *begin++;
}
}  // namespace _buff
LL read() {
  using namespace _buff;
  LL ret = 0;
  bool pos = true;
  char c = getc();
  for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
    assert(~c);
  }
  if (c == '-') {
    pos = false;
    c = getc();
  }
  for (; c >= '0' && c <= '9'; c = getc()) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
  }
  return pos ? ret : -ret;
}
template <typename T>
void chkMax(T &dp, const T &val) {
  if (val > dp) dp = val;
}
template <typename T>
void chkMin(T &dp, const T &val) {
  if (val < dp) dp = val;
}
bool check(int x) { return x > -2 && x < INT_MAX; }
int main() {
  int n = read();
  vector<int> arr(n + 1, -1);
  generate_n(&arr[1], n, read);
  vector<vector<int> > dp(n + 1, vector<int>{INT_MAX, -2});
  dp[0][0] = -1;
  dp[0][1] = 1e9;
  for (int i = 1; i <= n; ++i) {
    if (arr[i - 1] > arr[i]) chkMin(dp[i][0], dp[i - 1][0]);
    if (arr[i - 1] < arr[i]) chkMax(dp[i][1], dp[i - 1][1]);
    if (dp[i - 1][1] > arr[i]) chkMin(dp[i][0], arr[i - 1]);
    if (dp[i - 1][0] < arr[i]) chkMax(dp[i][1], arr[i - 1]);
  }
  if (!check(dp[n][0]) && !check(dp[n][1])) {
    return puts("NO"), 0;
  } else {
    puts("YES");
    vector<int> ans(n);
    for (int i = n, j = check(1); i; --i) {
      ans[i - 1] = j ^ 1;
      if (!j) {
        if (dp[i - 1][1] > arr[i] && dp[i][0] == arr[i - 1]) j = 1;
      } else {
        if (dp[i - 1][0] < arr[i] && dp[i][1] == arr[i - 1]) j = 0;
      }
    }
    for (int x : ans) printf("%d ", x);
  }
  return 0;
}
