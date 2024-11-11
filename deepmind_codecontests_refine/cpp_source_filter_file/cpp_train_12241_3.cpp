#include <bits/stdc++.h>
using namespace std;
char ans[205][205];
int mid = 101;
int vert = 0;
int last_type = 0;
int n;
int maxd = 0;
void print_left(int size) {
  size = maxd - size + 1;
  ans[mid][vert] = '|';
  for (int i = 0; i < size; ++i) {
    ans[mid + i][vert] = '|';
    ans[mid - i][vert] = '|';
  }
  ans[mid + size][vert] = '+';
  ans[mid - size][vert] = '+';
  ans[mid + size][vert + 1] = '-';
  ans[mid - size][vert + 1] = '-';
  last_type = 0;
  ++vert;
}
void print_right(int size) {
  size = maxd - size + 1;
  if (last_type == 0) vert += 3;
  ans[mid][vert] = '|';
  for (int i = 0; i < size; ++i) {
    ans[mid + i][vert] = '|';
    ans[mid - i][vert] = '|';
  }
  ans[mid + size][vert] = '+';
  ans[mid - size][vert] = '+';
  ans[mid + size][vert - 1] = '-';
  ans[mid - size][vert - 1] = '-';
  last_type = 1;
  ++vert;
}
string s;
void gen(int L, int R, int size = 1) {
  if (R - L < 2) return;
  if (R - L == 2) {
    print_left(size);
    print_right(size);
    return;
  }
  int b = 1;
  int last = -1;
  for (int i = L + 1; i < R && b != 0; ++i) {
    if (s[i] == '[') {
      b++;
    } else {
      b--;
    }
    last = i;
  }
  print_left(size);
  gen(L + 1, last, size + 1);
  print_right(size);
  gen(last + 1, R, size);
}
int main() {
  memset(ans, ' ', sizeof(ans));
  cin >> n;
  getline(cin, s);
  getline(cin, s);
  int d = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '[')
      d++;
    else
      d--;
    maxd = max(d, maxd);
  }
  gen(0, n);
  for (int i = 101 - maxd; i <= 101 + maxd; ++i) {
    for (int j = 0; j < vert; ++j) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
