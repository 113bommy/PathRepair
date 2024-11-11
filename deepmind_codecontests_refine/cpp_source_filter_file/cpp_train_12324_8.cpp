#include <bits/stdc++.h>
using namespace std;
uintmax_t x = 0;
size_t turns;
int main() {
  string op;
  cin >> turns;
  while (turns) {
    cin >> op;
    if (op[1] == '+')
      ++x;
    else
      --x;
    --turns;
  }
  cout << x << endl;
  return 0;
}
