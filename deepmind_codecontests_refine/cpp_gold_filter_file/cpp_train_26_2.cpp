#include <bits/stdc++.h>
using namespace std;
int num[10], cells[10];
bool used[10];
bool bt(int idx) {
  if (idx == 4) {
    if (num[0] == cells[0] + cells[1] && num[1] == cells[2] + cells[3] &&
        num[2] == cells[0] + cells[2] && num[3] == cells[1] + cells[3] &&
        num[4] == cells[0] + cells[3] && num[5] == cells[1] + cells[2])
      return true;
    else
      return false;
  } else {
    for (int i = 1; i <= 9; i++) {
      if (!used[i]) {
        cells[idx] = i;
        used[i] = true;
        if (bt(idx + 1)) return true;
        used[i] = false;
      }
    }
    return false;
  }
}
int main() {
  for (int i = 0; i < 6; i++) cin >> num[i];
  memset(used, false, sizeof used);
  memset(cells, -1, sizeof cells);
  if (bt(0))
    cout << cells[0] << " " << cells[1] << endl
         << cells[2] << " " << cells[3] << endl;
  else
    cout << -1 << endl;
}
