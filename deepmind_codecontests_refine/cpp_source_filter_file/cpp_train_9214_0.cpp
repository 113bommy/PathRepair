#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200;
int N;
char command[MaxN];
int main() {
  ios::sync_with_stdio(0);
  cin >> N;
  cin >> command;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x = 0, y = 0;
    for (int j = i; j < N; j++) {
      if (command[j] == 'U')
        y++;
      else if (command[j] == 'D')
        y--;
      else if (command[j] == 'R')
        x++;
      else if (command[j] == 'L')
        x--;
      if (x == 0 && y == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
