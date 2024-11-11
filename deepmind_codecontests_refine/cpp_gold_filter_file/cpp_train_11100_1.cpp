#include <bits/stdc++.h>
using namespace std;
long long int n, tmp;
long long int k, c = 0;
list<int> game;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    game.push_back(tmp);
  }
  while (*game.begin() != n) {
    if (*game.begin() > *(++game.begin())) {
      tmp = *(++game.begin());
      game.erase(++game.begin());
      game.push_back(tmp);
      c++;
    } else {
      tmp = *game.begin();
      game.erase(game.begin());
      game.push_back(tmp);
      c = 1;
    }
    if (c == k) {
      cout << *game.begin();
      return 0;
    }
  }
  cout << n;
  return 0;
}
