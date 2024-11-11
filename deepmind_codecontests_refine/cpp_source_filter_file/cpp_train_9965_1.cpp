#include <bits/stdc++.h>
using namespace std;
long long N, X, Y;
set<int> s;
int aV[20] = {0, 1, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};
int x[5];
void dfs(int cur, int M) {
  if (cur > N) {
    s.insert(M);
    return;
  } else {
    dfs(cur + 1, M + 1);
    dfs(cur + 1, M + 5);
    dfs(cur + 1, M + 10);
    dfs(cur + 1, M + 50);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> N;
  if (N <= 12)
    cout << aV[N];
  else
    cout << aV[12] + (N - 12) * 49;
  return 0;
}
