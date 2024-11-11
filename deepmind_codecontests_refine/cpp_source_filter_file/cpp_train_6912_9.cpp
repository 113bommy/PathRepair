#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cin.ignore();
  string moves;
  getline(cin, moves);
  int result = 0;
  for (int i = n - 1; i < moves.size(); i++) {
    if (moves[i - 1] == moves[i - 2] && moves[i - 1] == moves[i - 3]) {
      result++;
    }
  }
  cout << result << endl;
}
