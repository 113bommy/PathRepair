#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[8];
  for (int i = 0; i < 8; i++) cin >> s[i];
  char chess[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) chess[i][j] = s[i][j];
  }
  vector<int> W;
  vector<int> B;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (chess[i][j] == 'W') {
        int count_ = 0;
        int D = i;
        D--;
        while (D >= 0) {
          if (chess[D][j] == '.') {
            count_++;
            D--;
          } else {
            count_ = 0;
            break;
          }
        }
        if (count_ > 0) W.push_back(count_);
      } else if (chess[i][j] == 'B') {
        int count_ = 0;
        int D = i;
        D++;
        while (D <= 7) {
          if (chess[D][j] == '.') {
            count_++;
            D++;
          } else {
            count_ = 0;
            break;
          }
        }
        if (count_ > 0) B.push_back(count_);
      } else
        continue;
    }
  }
  if (W.size() > 0 && B.size() > 0) {
    sort(W.begin(), W.end());
    sort(B.begin(), B.end());
    if (W[0] <= B[0])
      cout << "A";
    else
      cout << "B";
  } else if (W.size() == 0)
    cout << "B";
  else
    cout << "A";
  return 0;
}
