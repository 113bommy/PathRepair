#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = 100;
long double P[N + 1][N + 1];
int n;
long double PR[N + 1][7];
long double solve(int win, int start, int end) {
  if (end - start == 1) {
    if (win == end)
      return P[win][start];
    else
      return P[win][end];
  }
  int mid = (start + end) / 2;
  pair<int, int> r1 = {start, mid}, r2 = {mid + 1, end};
  if (win > mid) swap(r1, r2);
  int score = (end - start + 1) / 2;
  long double ans = 0;
  long double val = 0;
  int l = log2(end - start + 1) + 1;
  long double f = solve(win, r1.first, r1.second);
  for (int w = r2.first; w <= r2.second; w++)
    ans = max(ans, PR[win][l] * score + f + solve(w, r2.first, r2.second));
  return ans;
}
void fill(int l, int start, int end) {
  if (l == 1) {
    PR[start][l] = 1;
    return;
  }
  int mid = (start + end) / 2;
  fill(l - 1, start, mid);
  fill(l - 1, mid + 1, end);
  for (int i = start; i <= mid; i++) {
    for (int j = mid + 1; j <= end; j++) {
      PR[i][l] += (long double)(P[i][j] * PR[i][l - 1] * PR[j][l - 1]);
    }
  }
  for (int i = mid + 1; i <= end; i++) {
    for (int j = start; j <= mid; j++) {
      PR[i][l] += PR[i][l - 1] * PR[j][l - 1] * P[i][j];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (1 << n); i++) {
    for (int j = 1; j <= (1 << n); j++) {
      cin >> P[i][j];
      P[i][j] /= 100.0;
    }
  }
  memset(PR, 0, sizeof(PR));
  fill(n + 1, 1, 1 << n);
  long double ans = 0;
  for (int i = 1; i <= (1 << n); i++) ans = max(ans, solve(i, 1, 1 << n));
  printf("%0.10Lf\n", ans);
  return 0;
}
