#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
using std::ios_base;
using std::pair;
using std::string;
using std::vector;
void move(bool move_left, string to_print) {
  if (move_left) {
    for (int i = to_print.length() - 1; i >= 0; i--) {
      cout << "PRINT " << to_print[i] << "\n";
      if (i == 0)
        continue;
      else
        cout << "LEFT\n";
    }
  } else
    for (int i = 0; i < to_print.length(); i++) {
      cout << "PRINT " << to_print[i] << "\n";
      if (i == to_print.length() - 1)
        continue;
      else
        cout << "RIGHT\n";
    }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, K;
  cin >> N >> K;
  string to_print;
  cin >> to_print;
  bool move_left;
  int num_printed = 0;
  if (K == 1)
    move(false, to_print);
  else if (K == N)
    move(true, to_print);
  else {
    move_left = (N - K) >= K;
    if (move_left) {
      for (int i = K; i >= 0; i--) cout << "LEFT\n";
      move(false, to_print);
    } else {
      for (int i = K; i < to_print.length(); i++) cout << "RIGHT\n";
      move(true, to_print);
    }
  }
  return 0;
}
