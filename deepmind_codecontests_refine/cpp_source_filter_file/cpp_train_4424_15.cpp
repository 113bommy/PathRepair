#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
char S[106];
int main() {
  gets(S + 1);
  int len = strlen(S + 1), flag = 0, ind = 1, s = 0;
  char T[] = "1CODEFORCES";
  for (int i = 1; i == ind; i++)
    if (T[ind] == S[i]) ind++;
  if (ind > strlen(T + 1)) flag = 1;
  for (int i = len, j = strlen(T + 1); i >= 1; i--) {
    if (T[j] == S[i])
      j--;
    else
      break;
    if (j == ind) flag = 1;
  }
  if (flag)
    puts("YES");
  else
    puts("NO");
}
