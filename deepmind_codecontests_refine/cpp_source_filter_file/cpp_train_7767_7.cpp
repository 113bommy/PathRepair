#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int N;
pair<int, int> DP[50][2];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    v.push_back(val);
  }
  DP[N - 1][0] = pair<int, int>(v[N - 1], 0);
  DP[N - 1][1] = pair<int, int>(0, v[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    int acum = 0, bob = 0, alice = 0;
    for (int j = i; j < N; j++) {
      int abob = v[j] + DP[j + 1][1].first;
      if (abob >= bob) {
        bob = abob;
        alice = DP[j + 1][1].second + acum;
      }
      acum += v[j];
    }
    DP[i][0] = pair<int, int>(bob, alice);
    acum = 0, bob = 0, alice = 0;
    for (int j = i; j < N; j++) {
      int aalice = v[j] + DP[j + 1][0].second;
      if (aalice >= alice) {
        alice = aalice;
        bob = DP[j + 1][0].first + acum;
      }
      acum += v[j];
    }
    DP[i][1] = pair<int, int>(bob, alice);
  }
  printf("%d %d\n", DP[0][0].second, DP[0][0].first);
  return 0;
}
