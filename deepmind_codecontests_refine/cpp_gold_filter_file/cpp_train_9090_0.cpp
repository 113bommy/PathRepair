#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN();
char a[1005], x[1005];
int h[1005], m[1005];
int main() {
  gets(a);
  int n = atoi(a), day = 1, cnt = 1;
  for (int i = 0; i < n; i++) {
    gets(a);
    h[i] = ((a[1] - '0') * 10 + (a[2] - '0')) % 12;
    m[i] = (a[4] - '0') * 10 + (a[5] - '0');
    x[i] = a[7];
    if (i == 0) continue;
    if (x[i] == x[i - 1] &&
        pair<int, int>(h[i], m[i]) == pair<int, int>(h[i - 1], m[i - 1]))
      cnt++;
    else
      cnt = 1;
    if (x[i] == 'a' && x[i - 1] == 'p')
      day++;
    else if (x[i] == x[i - 1] &&
             pair<int, int>(h[i], m[i]) < pair<int, int>(h[i - 1], m[i - 1]))
      day++;
    else if (cnt == 11)
      day++, cnt = 1;
  }
  printf("%d", day);
}
