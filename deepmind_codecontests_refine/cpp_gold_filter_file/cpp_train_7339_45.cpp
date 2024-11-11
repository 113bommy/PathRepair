#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch[8][8];
  for (int i = 0; i < 8; i++) {
    string temp;
    cin >> temp;
    for (int j = 0; j < 8; j++) ch[i][j] = temp[j];
  }
  int A_ans = 1000;
  int b_ans = 1000;
  for (int i = 0; i <= 7; i++) {
    for (int j = 0; j <= 7; j++) {
      if (ch[j][i] == 'W') {
        A_ans = min(A_ans, j);
        break;
      } else if (ch[j][i] == 'B')
        break;
      else
        continue;
    }
  }
  for (int i = 0; i <= 7; i++) {
    for (int j = 7; j >= 0; j--) {
      if (ch[j][i] == 'B') {
        b_ans = min(b_ans, 7 - j);
        break;
      } else if (ch[j][i] == 'W')
        break;
      else
        continue;
    }
  }
  if (A_ans <= b_ans)
    cout << "A" << endl;
  else
    cout << "B" << endl;
}
