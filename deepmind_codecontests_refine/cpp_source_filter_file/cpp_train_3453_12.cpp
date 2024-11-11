#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e5 + 5;
inline int read() {
  int res = 0, ch, flag = 0;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  return flag ? -res : res;
}
long long t, n, m, k;
long long sum, cnt;
int data[N];
void solve() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
    sum += data[i];
  }
  sort(data, data + n);
  for (int i = 0; i < n - 1; i++)
    if (data[i] == data[i + 1]) {
      cnt++;
      if (data[i] == 0 || cnt >= 2 || (i > 0 && data[i] == data[i - 1])) {
        puts("cslnb");
        return 0;
      }
    }
  sum -= n * (n - 1) / 2;
  if (sum & 1)
    puts("sjfnb");
  else
    puts("cslnb");
  return 0;
}
