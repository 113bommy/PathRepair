#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int n, *st;
  cin >> n;
  st = new int[n];
  int max = 1, k = 1, l = 2;
  cin >> c;
  st[0] = 1;
  for (int i = 1; i < n; i++) {
    cin >> c;
    if (c == '[') {
      k++;
      if (k > max) max = k;
      st[i] = k;
    }
    if (c == ']') {
      st[i] = -k;
      k--;
    }
    if (st[i - 1] > 0 && st[i] < 0)
      l += 3;
    else {
      if (st[i - 1] < 0 && st[i])
        l += 2;
      else
        l++;
    }
  }
  char **pic;
  pic = new char *[2 * max + 1];
  for (int i = 0; i < 2 * max + 1; i++) {
    pic[i] = new char[l];
    for (int j = 0; j < l; j++) pic[i][j] = ' ';
  }
  k = 0;
  for (int i = 0; i < n; i++) {
    int size = abs(st[i]) - 1;
    bool sn = (st[i] > 0);
    if (sn) {
      pic[0 + size][k] = '+';
      pic[0 + size][k + 1] = '-';
      pic[2 * max - size][k] = '+';
      pic[2 * max - size][k + 1] = '-';
      for (int j = 0 + size + 1; j < 2 * max - size; j++) pic[j][k] = '|';
      k++;
      if (st[i + 1] < 0) k += 2;
    } else {
      if (st[i - 1] > 0) k++;
      pic[0 + size][k] = '+';
      pic[0 + size][k - 1] = '-';
      pic[2 * max - size][k] = '+';
      pic[2 * max - size][k - 1] = '-';
      for (int j = 0 + size + 1; j < 2 * max - size; j++) pic[j][k] = '|';
      k++;
    }
  }
  for (int i = 0; i < 2 * max + 1; i++) {
    for (int j = 0; j < l; j++) cout << pic[i][j];
    cout << endl;
  }
}
