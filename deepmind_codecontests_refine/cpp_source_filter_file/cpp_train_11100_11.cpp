#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push(x);
  }
  int player = q.front();
  q.pop();
  long long score = 0;
  while (score < k) {
    if (player == n) break;
    int player2 = q.front();
    q.pop();
    if (player > player2) {
      score++;
      q.push(player2);
    } else {
      score = 0;
      q.push(player);
      player = player2;
    }
  }
  cout << player;
  return 0;
}
