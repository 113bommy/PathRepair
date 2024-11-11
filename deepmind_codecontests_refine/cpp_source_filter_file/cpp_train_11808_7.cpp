#include <bits/stdc++.h>
using namespace std;
int N, K, p[3001];
queue<pair<int, int> > boss;
int maxim[3001];
bool sel[3001][3001];
int sol;
void dfs(int A, int B, int runda) {
  if (runda > K) return;
  sel[A][B] = true;
  ++sol;
  if (A > N || B > N) return;
  if (p[A] > 0 && maxim[B] > 0 && sel[B + 1][B + 2] == false)
    dfs(B + 1, B + 2, runda + 1);
  if (p[A] < 100 && maxim[B] > 0 && sel[B][B + 1] == false)
    dfs(B, B + 1, runda + 1);
  if (p[A] > 0 && maxim[B] < 100 && sel[A][B + 1] == false)
    dfs(A, B + 1, runda + 1);
}
int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) cin >> p[i];
  for (int i = N; i >= 0; --i) maxim[i] = max(maxim[i + 1], p[i]);
  dfs(1, 2, 0);
  cout << sol;
  return 0;
}
