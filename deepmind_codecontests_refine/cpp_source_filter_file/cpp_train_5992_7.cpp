#include <bits/stdc++.h>
using namespace std;
int cards[110];
bool used[110];
bool allUsed(int N) {
  for (int i = 0; i < N; i++)
    if (!used[i]) return false;
  return true;
}
bool solve(int i, int N, int target) {
  if (i >= N && allUsed(N)) return true;
  if (used[i]) return solve(i + 1, N, target);
  used[i] = true;
  for (int e = i + 1; e < N; e++) {
    if (!used[e] && cards[e] + cards[i] == target) {
      used[e] = true;
      if (solve(i + 1, N, target)) {
        cout << i + 1 << " " << e + 1 << "\n";
        return true;
      }
      used[e] = false;
    }
  }
  used[i] = false;
  return false;
}
int main() {
  int N;
  cin >> N;
  memset(cards, 0, N);
  memset(used, false, N);
  int n = N;
  int tot = 0;
  for (int i = 0; i < N; i++) {
    int c;
    cin >> c;
    tot += c;
    cards[i] = c;
  }
  solve(0, N, tot / N * 2);
  return 0;
}
