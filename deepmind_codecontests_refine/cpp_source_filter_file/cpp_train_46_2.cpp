#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> errors;
void get_codes(unordered_map<int, int>& quantity, int cnt, int inc) {
  for (int i = 0; i < cnt; i++) {
    int code;
    cin >> code;
    quantity[code] += inc;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int bugs;
  cin >> bugs;
  get_codes(errors, bugs, 1);
  get_codes(errors, bugs - 1, -3);
  for (auto it = errors.begin(); it != errors.end(); ++it)
    if ((it->second) % 2 == 1) {
      cout << (it->first) << '\n';
      (it->second) -= 1;
    }
  get_codes(errors, bugs - 2, 2);
  for (auto it = errors.begin(); it != errors.end(); ++it)
    if ((it->second) != 0) cout << (it->first) << '\n';
}
