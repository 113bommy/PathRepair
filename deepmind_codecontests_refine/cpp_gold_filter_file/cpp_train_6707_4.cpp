#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<int> let(4);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'n') {
      let[0]++;
    } else if (s[i] == 'i') {
      let[1]++;
    } else if (s[i] == 'e') {
      let[2]++;
    } else if (s[i] == 't') {
      let[3]++;
    }
  }
  int res = 0;
  while (let[0] > 2 && let[1] > 0 && let[2] > 2 && let[3] > 0) {
    let[0] -= 2;
    let[1]--;
    let[2] -= 3;
    let[3]--;
    res++;
  }
  cout << res;
  return 0;
}
