#include <bits/stdc++.h>
using namespace std;
int main() {
  int n_people, n_chips, i;
  cin >> n_people >> n_chips;
  int answer = 0;
  int c_answer;
L1:
  for (i = 1; i <= n_people; i++) {
    c_answer = answer;
    answer += i;
    if (answer > n_chips) break;
  }
  if (answer <= n_chips) goto L1;
  cout << (n_chips - c_answer);
  return (0);
}
