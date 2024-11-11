#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<string> cards;
  set<char> digits, colors;
  for (int i = 0; i < N; i++) {
    string temp;
    cin >> temp;
    cards.push_back(temp);
    digits.insert(temp[1]);
    colors.insert(temp[0]);
  }
  char hints[] = {'R', 'G', 'B', 'Y', 'W', '1', '2', '3', '4', '5'};
  int bitmask, MAX = pow(2, 10);
  int res = 100;
  for (bitmask = 0; bitmask <= MAX; bitmask++) {
    bool dist[N + 1][N + 1];
    memset(dist, 0, sizeof(dist));
    int numHints = 0;
    for (int i = 0; i < 10; i++) {
      if (((bitmask >> i) & 1) != 0) {
        numHints++;
        for (int j = 0; j < N; j++) {
          for (int k = j + 1; k < N; k++) {
            if (i < 5 &&
                ((hints[i] == cards[j][0] && hints[i] != cards[k][0]) ||
                 (hints[i] != cards[j][0] && hints[i] == cards[k][0]) ||
                 cards[j] == cards[k]))
              dist[j][k] = dist[k][j] = 1;
            else if (i >= 5 &&
                     ((hints[i] == cards[j][1] && hints[i] != cards[k][1]) ||
                      (hints[i] != cards[j][1] && hints[i] == cards[k][1]) ||
                      cards[j] == cards[k]))
              dist[j][k] = dist[k][j] = 1;
          }
        }
      }
    }
    bool possible = true;
    for (int j = 0; j < N; j++)
      for (int k = j + 1; k < N; k++)
        if (dist[j][k] != 1) possible = false;
    if (!possible) {
      possible = true;
      for (int i = 0; i < N - 1; i++)
        if (cards[i] != cards[i + 1]) possible = false;
    }
    if (possible) res = min(res, numHints);
  }
  cout << res;
  return 0;
}
