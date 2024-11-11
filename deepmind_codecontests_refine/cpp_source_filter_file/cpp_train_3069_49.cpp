#include <bits/stdc++.h>
using namespace std;
long ans;
string st;
long cost(char c) {
  if (c == 'Q') return 9;
  if (c == 'R') return 5;
  if (c == 'B') return 3;
  if (c == 'K') return 3;
  if (c == 'P') return 1;
  if (c == 'q') return -9;
  if (c == 'r') return -5;
  if (c == 'b') return -3;
  if (c == 'k') return -3;
  if (c == 'p') return -1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 1; i <= 8; i++) {
    cin >> st;
    for (int j = 0; j < st.size(); j++) {
      ans += cost(st[j]);
    }
  }
  if (ans > 0)
    cout << "White" << endl;
  else if (ans == 0)
    cout << "Draw" << endl;
  else
    cout << "Black" << endl;
  cin.get();
  cin.get();
  return 0;
}
