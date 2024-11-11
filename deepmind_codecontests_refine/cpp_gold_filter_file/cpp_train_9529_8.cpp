#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  int num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
long long A[200005];
vector<long long> V[201005];
int main() {
  int n = getnum(), k = getnum(), mn = 40000000, ans = 0;
  for (int i = 0; i <= n; i++) {
    int x = i, y = getnum();
    A[i] = y;
    V[i].push_back(y);
  }
  for (int i = 0; i <= n; i++) {
    long long x = 0, y = i;
    for (int j = 0; j < V[i].size(); j++) x += V[i][j];
    V[i].clear();
    if (x == 0) continue;
    while (x % 2 == 0 && y < n) y++, x /= 2;
    V[y].push_back(x);
    if (V[i].size() > 0) mn = min(mn, i);
  }
  for (int i = n; i >= 0; i--) {
    long long x = 0;
    for (int j = 0; j < V[i].size(); j++) x += V[i][j];
    if (abs(x - A[i]) > k)
      ;
    else if (i <= mn) {
      if (i != n)
        ans++;
      else if (x != A[i])
        ans++;
    }
    if (abs(x) > LLONG_MAX / 2) break;
    V[i - 1].push_back(x * 2);
  }
  cout << ans;
}
