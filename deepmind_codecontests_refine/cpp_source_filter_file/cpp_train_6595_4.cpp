#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
bool gao(int a, int b) {
  int ret = 0;
  int cnt = 0;
  while (a != 1 && a != 0) {
    ret += b / a - 1;
    cnt += b / a;
    int r = b % a;
    b = a;
    a = r;
  }
  if (a == 0) return false;
  ret += (b - a) - 1;
  cnt += (b - a);
  a = 1;
  b = 1;
  cnt++;
  if (cnt == n && ret < ans) {
    ans = ret;
    return true;
  }
  return false;
}
char ch;
void inv(char &ch) {
  if (ch == 'T')
    ch = 'B';
  else
    ch = 'T';
}
void print(int a, int b) {
  if (a == 1) {
    cout << "T";
    for (int i = 0; i < b - 1; i++) cout << "B";
    ch = 'T';
    return;
  }
  int r = b % a;
  print(r, a);
  for (int i = 0; i < b / a; i++) cout << ch;
  inv(ch);
}
int main() {
  int r;
  while (cin >> n >> r) {
    if (r == 1) {
      if (n == 1) {
        cout << 1 << endl;
        cout << "T" << endl;
      } else {
        cout << "IMPOSSIBLE" << endl;
      }
      continue;
    }
    ans = 100000000;
    int num = -1;
    for (int i = 1; i <= r; i++) {
      if (gao(i, r)) {
        num = i;
      }
    }
    if (ans == 100000000) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << ans << endl;
      print(num, r);
      cout << endl;
    }
  }
  return 0;
}
