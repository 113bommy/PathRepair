#include <bits/stdc++.h>
using namespace std;
int main() {
  int n(0);
  cin >> n;
  vector<char> cards(n);
  int r(0), g(0), b(0);
  for (int i = 0; i < n; ++i) {
    cin >> cards[i];
    switch (cards[i]) {
      case 'R':
        ++r;
        break;
      case 'G':
        ++g;
        break;
      case 'B':
        ++b;
        break;
      default:
        cout << "Not a valid color!" << endl;
        exit(1);
    }
  }
  if ((r > 0) and (g > 0) and (b > 0)) {
    cout << "BGR" << endl;
    exit(0);
  }
  if ((r > 0) and (g > 0) and (b == 0)) {
    if ((r >= 2) and (g >= 2)) {
      cout << "BGR" << endl;
      exit(0);
    }
    if ((r == 1) and (g == 1)) {
      cout << "B" << endl;
      exit(0);
    }
    if (r >= 2) {
      cout << "BG" << endl;
      exit(0);
    } else {
      cout << "BR" << endl;
      exit(0);
    }
  }
  if ((g > 0) and (b > 0) and (r == 0)) {
    if ((g >= 2) and (b >= 0)) {
      cout << "BGR" << endl;
      exit(0);
    }
    if ((g == 1) and (b == 1)) {
      cout << "R" << endl;
      exit(0);
    }
    if (g >= 2) {
      cout << "BR" << endl;
      exit(0);
    } else {
      cout << "GR" << endl;
      exit(0);
    }
  }
  if ((b > 0) and (r > 0) and (g == 0)) {
    if ((b >= 2) and (r >= 2)) {
      cout << "BGR" << endl;
      exit(0);
    }
    if ((b == 1) and (r == 1)) {
      cout << "G" << endl;
      exit(0);
    }
    if (b >= 2) {
      cout << "GR" << endl;
      exit(0);
    } else {
      cout << "BG" << endl;
      exit(0);
    }
  }
  if (b > 0) cout << "B" << endl;
  if (g > 0) cout << "G" << endl;
  if (r > 0) cout << "R" << endl;
}
