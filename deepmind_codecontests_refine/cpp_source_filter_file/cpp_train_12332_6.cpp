#include <bits/stdc++.h>
using namespace std;
int v[7], k;
char want[5];
int trans(char s[]) {
  if (s[0] == 'S') return 1;
  if (s[0] == 'M') return 2;
  if (s[0] == 'L') return 3;
  if (s[1] == 'X') return 5;
  return 4;
}
int main() {
  int i, j;
  cin >> v[1] >> v[2] >> v[3] >> v[4] >> v[5] >> k;
  for (j = 1; j <= k; ++j) {
    cin >> want;
    switch (trans(want)) {
      case 1:
        i = 1;
        while (!v[i]) ++i;
        --v[i];
        switch (i) {
          case 1:
            cout << "S\n";
            break;
          case 2:
            cout << "M\n";
            break;
          case 3:
            cout << "L\n";
            break;
          case 4:
            cout << "XL\n";
            break;
          case 5:
            cout << "XXL\n";
            break;
        }
        break;
      case 2:
        if (v[2])
          --v[2], cout << "M\n";
        else if (v[3])
          --v[3], cout << "L\n";
        else if (v[1])
          --v[1], cout << "S\n";
        else if (v[4])
          --v[4], cout << "XL\n";
        else
          --v[5], cout << "XXL\n";
        break;
      case 3:
        if (v[3])
          --v[3], cout << "L\n";
        else if (v[4])
          --v[4], cout << "XL\n";
        else if (v[2])
          --v[2], cout << "M\n";
        else if (v[1])
          --v[1], cout << "S\n";
        else
          --v[5], cout << "XXL\n";
        break;
      case 4:
        if (v[4])
          --v[4], cout << "XL\n";
        else if (v[5])
          --v[5], cout << "XXL\n";
        else if (v[3])
          --v[3], cout << "L\n";
        else if (v[2])
          --v[2], cout << "M\n";
        else
          --v[1], cout << "S\n";
        break;
      case 5:
        i = 5;
        while (!v[i]) --i;
        --v[i];
        switch (i) {
          case 1:
            cout << "S\n";
            break;
          case 2:
            cout << "M\n";
            break;
          case 3:
            cout << "L\n";
            break;
          case 4:
            cout << "XL\n";
            break;
          case 5:
            cout << "XXL\n";
            break;
        }
        break;
    }
  }
  return 0;
}
