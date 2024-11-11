#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int N, M;
char S[MAXN][MAXN];
bool good[MAXN];
bool temp[MAXN];
bool check(int idx) {
  memset(temp, 0, sizeof(temp));
  for (int i = 1; i < N; i++) {
    if (good[i]) continue;
    if (S[i - 1][idx] < S[i][idx])
      temp[i] = true;
    else if (S[i - 1][idx] > S[i][idx])
      return false;
  }
  for (int i = 1; i < N; i++)
    if (!good[i] && temp[i]) good[i] = true;
  return true;
}
int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> S[i];
  int ans = 0;
  for (int i = 0; i < M; i++)
    if (!check(i)) ans++;
  cout << ans << "\n";
  return 0;
}
