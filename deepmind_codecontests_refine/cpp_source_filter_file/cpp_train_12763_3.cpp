#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &FF) {
  int RR = 1;
  FF = 0;
  char CH = getchar();
  for (; !isdigit(CH); CH = getchar())
    if (CH == '-') RR = -RR;
  for (; isdigit(CH); CH = getchar()) FF = FF * 10 + CH - 48;
  FF *= RR;
}
inline void file(string str) {
  freopen((str + ".in").c_str(), "r", stdin);
  freopen((str + ".out").c_str(), "w", stdout);
}
const int N = 2e6 + 10;
int n, seq[N], tax[N], li, ri;
int main() {
  read(n);
  long long res = 0, ans = 0;
  int id = 0;
  for (int i = 1; i <= n; i++) {
    read(seq[i]);
    if (i < n) {
      if (seq[i] <= i)
        ri++;
      else
        tax[i - seq[i]]++, li++;
    }
    res += abs(seq[i] - i);
  }
  ans = res;
  for (int i = 1; i <= n - 1; i++) {
    res = res - li + ri;
    res = res + 2 * seq[n - i + 1] - n - 1;
    li -= tax[i], ri += tax[i];
    if (seq[n - i + 1] != 1) ri--, li++;
    tax[i + seq[n - i + 1] - 1]++;
    if (res < ans) ans = res, id = i;
  }
  cout << ans << " " << id << endl;
  return 0;
}
