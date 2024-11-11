#include <bits/stdc++.h>
using namespace std;
int N, M, rez = 1;
pair<int, int> V[100005 << 1];
int F[100005 << 1];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> V[i].first, V[i].second = i;
  for (int i = N + 1; i <= 2 * N; i++) cin >> V[i].first, V[i].second = i - N;
  cin >> M;
  F[0] = 1;
  for (int i = 1; i <= 2 * N; i++) F[i] = (1LL * F[i - 1] * i) % M;
  sort(V + 1, V + 2 * N + 1);
  for (int i = 1, eq = 0, dist = 0, ex = 0; i <= 2 * N; i++) {
    if (V[i].first == ex) {
      dist++;
      if (V[i].second == V[i - 1].second) eq += 2;
    } else {
      rez = (1LL * rez * F[dist - eq]) % M;
      for (int j = dist, add, pas = 2; pas <= eq; j -= 2, pas += 2) {
        add = (1LL * j * (j - 1) / 2) % M;
        rez = (1LL * rez * add) % M;
      }
      ex = V[i].first, eq = 0, dist = 1;
    }
  }
  cout << rez << "\n";
  return 0;
}
