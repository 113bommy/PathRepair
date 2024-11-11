#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int minReal[2000];
int INFI = 99999999;
void init() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= M; ++i) minReal[i] = 99999999;
  for (int i = 0; i < N; ++i) {
    int id;
    int real;
    scanf("%d%d", &id, &real);
    minReal[id] = min(minReal[id], real);
  }
}
void deal() {
  int ans = 0;
  for (int i = 1; i < M; ++i) {
    ans += minReal[i];
  }
  ans = min(ans, K);
  cout << ans << endl;
}
int main() {
  init();
  deal();
  return 0;
}
