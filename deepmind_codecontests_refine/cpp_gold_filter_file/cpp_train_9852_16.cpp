#include <bits/stdc++.h>
using namespace std;
struct IO_Tp {
  bool is_digit(const char ch) { return '0' <= ch && ch <= '9'; }
  IO_Tp& operator>>(int& res) {
    res = 0;
    static char ch;
    while (ch = getchar(), !is_digit(ch))
      ;
    do (res *= 10) += ch & 15;
    while (ch = getchar(), is_digit(ch));
    return *this;
  }
} IO;
int N, M, C, P, Ans;
int arr[1005];
int main(int argc, char** argv) {
  IO >> N >> M >> C;
  int cur1(1), cur2(N + 1);
  while (M-- && cur1 != cur2) {
    IO >> P;
    if (P <= C / 2) {
      if (cur1 == 1)
        arr[Ans = cur1++] = P;
      else {
        arr[Ans = upper_bound(arr + 1, arr + cur1, P) - arr] = P;
        cur1 += cur1 == Ans;
      }
    } else {
      if (cur2 == N + 1)
        arr[Ans = --cur2] = P;
      else {
        arr[Ans = lower_bound(arr + cur2, arr + N + 1, P) - 1 - arr] = P;
        cur2 -= cur2 - 1 == Ans;
      }
    }
    printf("%d\n", Ans);
    fflush(stdout);
  }
  return 0;
}
