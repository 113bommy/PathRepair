#include <bits/stdc++.h>
using namespace std;
struct state {
  int n[6];
  bool operator==(state b) {
    for (int i = 0; i < 6; i++)
      if (n[i] != b.n[i]) return false;
    return true;
  }
};
state ans[11];
int main() {
  state a;
  memset(a.n, 0, sizeof a.n);
  for (int i = 0; i < 6; i++) {
    char c;
    cin >> c;
    if (c == 'G')
      a.n[0]++;
    else if (c == 'R')
      a.n[1]++;
    else if (c == 'O')
      a.n[2]++;
    else if (c == 'Y')
      a.n[3]++;
    else if (c == 'B')
      a.n[4]++;
    else
      a.n[5]++;
  }
  sort(a.n, a.n + 6);
  state b[11] = {{1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 2}, {0, 0, 1, 1, 1, 3},
                 {0, 0, 0, 1, 1, 4}, {0, 0, 0, 0, 1, 5}, {0, 0, 0, 0, 0, 6},
                 {0, 0, 1, 1, 2, 2}, {0, 0, 0, 2, 2, 2}, {0, 0, 0, 1, 2, 3},
                 {0, 0, 0, 0, 2, 4}, {0, 0, 0, 0, 3, 3}};
  int index = find(b, b + sizeof b, a) - b;
  index++;
  if (index > 11)
    cout << " not found " << endl;
  else {
    int ans = 6;
    if (index == 4 || index == 10 || index == 11)
      ans = 2;
    else if (index == 5 || index == 6)
      ans = 1;
    else if (index == 3)
      ans = 5;
    else if (index == 9)
      ans = 3;
    else if (index == 2)
      ans = 15;
    else if (index == 1)
      ans = 30;
    else if (index == 7)
      ans = 8;
    cout << ans;
  }
  return 0;
}
