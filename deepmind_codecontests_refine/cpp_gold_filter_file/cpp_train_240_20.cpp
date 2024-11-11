#include <bits/stdc++.h>
using namespace std;
bool do_i_win(long long int a, long long int b) {
  if (a == 0) return 0;
  if (a == 1) return 1;
  if (b % a == 0) return 1;
  bool next_turn = do_i_win(b % a, a);
  if (next_turn == 0)
    return 1;
  else {
    long long int x = (b / a) % (a + 1);
    if (x & 0x1)
      return 0;
    else
      return 1;
  }
}
int main(void) {
  int n;
  long long int a, b;
  bool result;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a < b)
      result = do_i_win(a, b);
    else
      result = do_i_win(b, a);
    if (result == 1)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
  return 0;
}
