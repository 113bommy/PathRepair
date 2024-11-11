#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
struct player {
  int i;
  int j;
  int pos;
};
int main() {
  bool firstwon1 = false;
  bool secondwon1 = false;
  bool firstwon2 = false, firstwon3 = false, firstwon4 = false;
  bool secondwon2 = false, secondwon3 = false, secondwon4 = false;
  int won = 0;
  player a[2], b[2];
  cin >> a[0].i >> a[0].j;
  cin >> a[1].i >> a[1].j;
  cin >> b[0].i >> b[0].j;
  cin >> b[1].i >> b[1].j;
  if (a[0].i > b[1].j && a[1].j > b[0].i) firstwon1 = true;
  if (a[0].i < b[1].j && a[1].j < b[0].i) secondwon1 = true;
  if (a[0].i > b[0].j && a[1].j > b[1].i) firstwon2 = true;
  if (a[0].i < b[0].j && a[1].j < b[1].i) secondwon2 = true;
  if (a[1].i > b[1].j && a[0].j > b[0].i) firstwon3 = true;
  if (a[1].i < b[1].j && a[0].j < b[0].i) secondwon3 = true;
  if (a[1].i > b[0].j && a[0].j > b[1].i) firstwon4 = true;
  if (a[1].i < b[0].j && a[0].j < b[1].i) secondwon4 = true;
  if ((firstwon1 == true && firstwon2 == true) ||
      (firstwon3 == true && firstwon4 == true))
    won = 1;
  if ((secondwon1 == true || secondwon2 == true) &&
      (secondwon3 == true || secondwon4 == true))
    won = 2;
  switch (won) {
    case 1: {
      cout << "Team 1\n";
      break;
    }
    case 2: {
      cout << "Team 2\n";
      break;
    }
    case 0: {
      cout << "Draw\n";
      break;
    }
  }
  return 0;
}
