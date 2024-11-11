#include <bits/stdc++.h>
using namespace std;
typedef struct recahrge {
  int day;
  int amt;
} recharge_t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, P, M;
  cin >> N >> P >> M;
  recharge_t rec[N];
  for (int i = 0; i < N; i++) {
    cin >> rec[i].day >> rec[i].amt;
  }
  long long balance = 0;
  int negCount = 0;
  int j = 0;
  for (int i = 1; i <= M; i++) {
    if (i == rec[j].day) {
      balance += rec[j].amt;
      j++;
    }
    balance -= P;
    if (balance < 0) negCount++;
  }
  cout << negCount;
  return 0;
}
