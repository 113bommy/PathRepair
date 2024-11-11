#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ships, ship_length, k;
  cin >> n >> ships >> ship_length >> k;
  string w;
  cin >> w;
  vector<int> position;
  position.push_back(-1);
  for (int i = 0; i < w.size(); i++) {
    if (w[i] == '1') position.push_back(i);
  }
  position.push_back(n);
  vector<int> moves;
  for (int i = 1; i < position.size(); i++) {
    int prev = position[i - 1];
    int pos = position[i];
    while (pos - ship_length > prev) {
      pos = pos - ship_length;
      moves.push_back(pos);
    }
  }
  for (int i = 1; i < ships; i++) moves.pop_back();
  cout << moves.size() << endl;
  for (int i = 0; i < moves.size(); i++) {
    int pos = moves[i];
    if (i) cout << " ";
    cout << pos + 1;
  }
  cout << endl;
}
