#include <bits/stdc++.h>
using namespace std;
int n, m;
inline int Read() {
  int y = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    y = y * 10 + (c - '0'), c = getchar();
  }
  return y * f;
}
inline void read(int &x) { x = Read(); }
char a[1000005], b[1000005];
int nxt[1000005];
void work() {
  cin >> a + 1;
  int n = strlen(a + 1);
  int j = 0;
  nxt[1] = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1) continue;
    while (j > 0 && (a[j + 1] != a[i])) {
      j = nxt[j];
    }
    if (a[i] == a[j + 1]) ++j;
    nxt[i] = j;
  }
  int Max = 0;
  for (int i = 1; i <= n - 1; i++) Max = max(Max, nxt[i]);
  int Ans = nxt[n];
  if (!Ans || !Max) {
    cout << "Just a legend";
  } else {
    int j = nxt[n];
    while (j > Max) j = nxt[j];
    if (!j) {
      cout << "Just a legend";
      return;
    }
    for (int i = 1; i <= j; i++) cout << a[i];
  }
}
int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}
