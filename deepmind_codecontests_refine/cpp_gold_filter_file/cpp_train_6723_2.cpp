#include <bits/stdc++.h>
using namespace std;
unsigned long long A, B, pow2[65], sum, ans;
bool pd;
void dfs(int t, int d) {
  if (t == -1) {
    if (d == 0) {
      cout << A - sum << " " << sum << endl;
    }
    exit(0);
  }
  unsigned long long ta = pow2[t] & A, tb = pow2[t] & B;
  if (ta) ta = 1;
  if (tb) tb = 1;
  if (tb == 0) {
    if (d == 1) {
      sum += pow2[t];
      if (ta == 1) dfs(t - 1, 1);
      if (ta == 0) dfs(t - 1, 0);
      sum -= pow2[t];
    }
    if (d == 0) {
      if (ta == 1) dfs(t - 1, 1);
      if (ta == 0) dfs(t - 1, 0);
    }
  }
  if (tb == 1) {
    if (d == 1) {
      sum += pow2[t];
      if (ta == 0) dfs(t - 1, 1);
      sum -= pow2[t];
    }
    if (d == 0) {
      sum += pow2[t];
      if (ta == 1) dfs(t - 1, 0);
      sum -= pow2[t];
    }
  }
}
int main() {
  cin >> A >> B;
  pow2[0] = 1;
  for (int i = 1; i <= 63; i++) pow2[i] = pow2[i - 1] * 2;
  pd = false;
  sum = 0;
  dfs(63, 0);
  cout << "-1\n";
  return 0;
}
