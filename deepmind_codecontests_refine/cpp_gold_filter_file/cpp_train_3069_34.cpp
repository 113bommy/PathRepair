#include <bits/stdc++.h>
using namespace std;
int main() {
  int bl = 0;
  int wh = 0;
  for (int i = 0; i < 8; i++) {
    string k;
    cin >> k;
    for (int j = 0; j < k.size(); j++) {
      if (k[j] >= 'a' && k[j] <= 'z') {
        if (k[j] == 'r') bl += 5;
        if (k[j] == 'b' || k[j] == 'n') bl += 3;
        if (k[j] == 'q') bl += 9;
        if (k[j] == 'p') bl++;
      }
      if (k[j] > 'A' && k[j] <= 'Z') {
        if (k[j] == 'N' || k[j] == 'B') wh += 3;
        if (k[j] == 'Q') wh += 9;
        if (k[j] == 'R') wh += 5;
        if (k[j] == 'P') wh++;
      }
    }
  }
  if (bl > wh) cout << "Black" << endl;
  if (bl < wh) cout << "White" << endl;
  if (bl == wh) cout << "Draw" << endl;
}
