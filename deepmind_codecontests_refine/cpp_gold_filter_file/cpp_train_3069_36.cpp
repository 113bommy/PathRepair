#include <bits/stdc++.h>
using namespace std;
long long j, i, hitam, putih;
char a;
int main() {
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> a;
      if (a == 'P') putih++;
      if (a == 'p') hitam++;
      if (a == 'Q') putih += 9;
      if (a == 'q') hitam += 9;
      if (a == 'R') putih += 5;
      if (a == 'r') hitam += 5;
      if (a == 'B' || a == 'N') putih += 3;
      if (a == 'b' || a == 'n') hitam += 3;
    }
  }
  if (putih == hitam)
    cout << "Draw" << endl;
  else if (putih > hitam)
    cout << "White" << endl;
  else
    cout << "Black" << endl;
}
