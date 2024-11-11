#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, steps;
  cin >> n >> m >> steps;
  if (steps <= n) {
    cout << steps + 1 << " " << 1 << endl;
    return 0;
  }
  long long int pseudo_steps = steps - n;
  long long int col = m - 1;
  long long int level = pseudo_steps / col;
  long long int go_right = level % 2 == 0 ? 1 : 0;
  long long int remain = pseudo_steps % col;
  long long int row = n - level;
  long long int column;
  if (go_right) {
    column = remain + 1;
  } else {
    column = col - remain;
  }
  cout << row << " " << column + 1 << endl;
}
