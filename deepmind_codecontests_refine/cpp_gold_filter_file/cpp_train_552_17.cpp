#include <bits/stdc++.h>
using namespace std;
struct team {
  int solved;
  int penalty;
  bool operator<(const team &q) const {
    return solved == q.solved ? penalty < q.penalty : solved > q.solved;
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  team teams[n];
  for (int i = 0; i < n; i++) {
    cin >> teams[i].solved >> teams[i].penalty;
  }
  sort(teams, teams + n);
  int ranks[n];
  ranks[0] = 1;
  for (int i = 0; i < n; i++) {
    if (teams[i].solved == teams[i - 1].solved &&
        teams[i].penalty == teams[i - 1].penalty) {
      ranks[i] = ranks[i - 1];
    } else {
      ranks[i] = i + 1;
    }
  }
  k--;
  int tofind = ranks[k];
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (ranks[i] == tofind) count++;
  }
  cout << count << "\n";
}
