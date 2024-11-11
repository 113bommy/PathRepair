#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x;
  bool player;
  int game1 = 0, game2 = 0;
  deque<int> ho;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ho.push_front(x);
  }
  while (!ho.empty()) {
    if (player == 1) {
      if (ho.front() > ho.back()) {
        game1 += ho.front();
        ho.pop_front();
        player = 0;
      } else {
        game1 += ho.back();
        ho.pop_back();
        player = 0;
      }
    } else {
      if (ho.front() > ho.back()) {
        game2 += ho.front();
        ho.pop_front();
        player = 1;
      } else {
        game2 += ho.back();
        ho.pop_back();
        player = 1;
      }
    }
  }
  cout << game2 << " " << game1;
  return 0;
}
