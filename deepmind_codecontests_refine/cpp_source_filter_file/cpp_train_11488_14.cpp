#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 20;
const double PI = M_PI;
const double EPS = 1e-15;
const int MaxN = 10 + 5, MaxM = 100 + 5;
int N, M, K;
string name;
int a[MaxN][MaxM];
int b[MaxN][MaxM];
int c[MaxN][MaxM];
int pos[MaxM];
int planetB;
int planetS;
bool cmp(int item1, int item2) {
  int costItem1 = b[planetS][item1] - a[planetB][item1];
  int costItem2 = b[planetS][item2] - a[planetB][item2];
  return costItem1 > costItem2;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    cin >> name;
    for (int j = 0; j < M; j++) cin >> a[i][j] >> b[i][j] >> c[i][j];
  }
  for (int i = 0; i < M; i++) pos[i] = i;
  int answer = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      planetB = i;
      planetS = j;
      sort(pos, pos + M, cmp);
      int tot = 0, profit = 0;
      for (int k = 0; k < N; k++) {
        int item = pos[k];
        int cost = b[planetS][item] - a[planetB][item];
        if (cost <= 0) break;
        if (tot + c[planetB][item] <= K) {
          tot = tot + c[planetB][item];
          profit = profit + c[planetB][item] * cost;
        } else {
          profit = profit + (K - tot) * cost;
          tot = K;
        }
      }
      answer = max(answer, profit);
    }
  cout << answer << endl;
  return 0;
}
