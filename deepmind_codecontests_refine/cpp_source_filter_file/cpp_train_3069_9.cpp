#include <bits/stdc++.h>
using namespace std;
string a[8];
int main() {
  long i = 0, j = 0, sb = 0, sw = 0;
  for (i = 0; i < 8; i++) {
    cin >> a[i];
    for (j = 0; j < 8; j++) switch (a[i][j]) {
        case 'Q': {
          sw += 9;
          break;
        }
        case 'R': {
          sw += 5;
          break;
        }
        case 'B': {
          sw += 3;
          break;
        }
        case 'N': {
          sw += 3;
          break;
        }
        case 'P': {
          sw += 3;
          break;
        }
        case 'K': {
          sw += 0;
          break;
        }
        case 'q': {
          sb += 9;
          break;
        }
        case 'r': {
          sb += 5;
          break;
        }
        case 'b': {
          sb += 3;
          break;
        }
        case 'n': {
          sb += 3;
          break;
        }
        case 'p': {
          sb += 1;
          break;
        }
        case 'k': {
          sb += 0;
          break;
        }
      }
  }
  if (sw > sb) cout << "White" << endl;
  if (sw < sb) cout << "Black" << endl;
  if (sw == sb) cout << "Draw" << endl;
  return 0;
}
