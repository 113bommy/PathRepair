#include <bits/stdc++.h>
using namespace std;
const int MAXK = 105;
const int MAXN = 505;
const int MAXM = 1e5 + 5;
int n, k;
long long h[MAXN];
long long memo[MAXN][MAXN * MAXK];
int cardCnt[MAXM], demandCnt[MAXM];
long long calcState(int cards, int players) {
  if (cards == 0 || players == 0) return 0;
  if (memo[players][cards] != -1) return memo[players][cards];
  long long answer = 0;
  for (int i = 0; i <= min(k, cards); i++) {
    answer = max(answer, h[i] + calcState(cards - i, players - 1));
  }
  memo[players][cards] = answer;
  return answer;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long answer = 0;
  cin >> n >> k;
  for (int i = 0; i < n * k; i++) {
    int x;
    cin >> x;
    cardCnt[x]++;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    demandCnt[x]++;
  }
  for (int i = 1; i <= k; i++) {
    cin >> h[i];
  }
  memset(memo, -1, sizeof(memo));
  for (int i = 1; i < MAXM; i++) {
    answer += calcState(cardCnt[i], demandCnt[i]);
  }
  cout << answer << '\n';
}
