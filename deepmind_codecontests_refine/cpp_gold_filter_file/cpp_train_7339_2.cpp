#include <bits/stdc++.h>
using namespace std;
struct pawn {
  long long int r;
  long long int c;
};
struct pawn b[100], w[100];
int main() {
  ios::sync_with_stdio(false);
  char a;
  long long int l = 0, h = 0;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> a;
      if (a == 'B') {
        b[l].r = i;
        b[l].c = j;
        l++;
      } else if (a == 'W') {
        w[h].r = i;
        w[h].c = j;
        h++;
      }
    }
  }
  long long int w_r, w_c;
  for (int i = 0; i < h; i++) {
    int f = 0;
    for (int j = 0; j < l; j++) {
      if (b[j].r < w[i].r && b[j].c == w[i].c) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      w_r = w[i].r;
      w_c = w[i].c;
      break;
    }
  }
  long long int b_r, b_c;
  for (int i = l - 1; i >= 0; i--) {
    int f = 0;
    for (int j = h - 1; j >= 0; j--) {
      if (w[j].r > b[i].r && w[j].c == b[i].c) {
        f = 1;
        break;
      }
    }
    if (f == 0) {
      b_r = b[i].r;
      b_c = b[i].c;
      break;
    }
  }
  long long int diff_w = w_r - 1;
  long long int diff_b = 8 - b_r;
  if (diff_w == diff_b)
    cout << "A" << endl;
  else if (diff_w < diff_b)
    cout << "A" << endl;
  else
    cout << "B" << endl;
  return 0;
}
