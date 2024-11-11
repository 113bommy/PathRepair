#include <bits/stdc++.h>
using namespace std;
queue<int> deck[2];
set<pair<string, string>> visited;
pair<string, string> getState() {
  string s[2];
  for (int k = 0; k < 2; k++)
    for (int i = 0; i < deck[k].size(); i++) {
      int x = deck[k].front();
      deck[k].pop();
      s[k] += (x - 1 + '0');
      deck[k].push(x);
    }
  return make_pair(s[0], s[1]);
}
bool gameRunning() { return (deck[0].size() > 0 && deck[1].size() > 0); }
void displayQueues() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < deck[i].size(); j++) {
      int x = deck[i].front();
      deck[i].pop();
      cout << x << " ";
      deck[i].push(x);
    }
    cout << "\n";
  }
  cout << "\n";
}
int cardsGame() {
  int count = 0;
  while (gameRunning()) {
    pair<string, string> state = getState();
    if (visited.count(state)) return -1;
    visited.insert(state);
    int cards[2];
    for (int i = 0; i < 2; i++) {
      cards[i] = deck[i].front();
      deck[i].pop();
    }
    count++;
    int winning = cards[0] < cards[1];
    deck[winning].push(cards[1 - winning]);
    deck[winning].push(cards[winning]);
  }
  return count;
}
int whoWon() { return (deck[0].size() == 0) + 1; }
int main() {
  int n, k, x;
  cin >> n;
  for (int i = 0; i < 2; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> x;
      deck[i].push(x);
    }
  }
  int result = cardsGame();
  cout << result;
  if (result != -1) cout << " " << whoWon();
  return 0;
}
