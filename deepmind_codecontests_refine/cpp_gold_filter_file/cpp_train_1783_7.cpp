#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
string ans;
void repeat(string x, int cnt) {
  while (cnt--) ans += x;
}
void setx(int x) {
  repeat("l", 50);
  repeat("lt", 55);
  repeat("r", x - 1);
}
void sety(int x) {
  repeat("d", 10);
  repeat("dt", 15);
  repeat("u", x - 1);
}
void init() {
  repeat("d", 21);
  repeat("0l", 100);
  repeat("0u", 23);
  repeat("d", 1);
  repeat("r", 70);
  repeat("0rst", 30);
  setx(70);
  repeat("d", 1);
  repeat("0rst", 30);
  setx(100);
  sety(19);
}
void copy() {
  for (int i = 100; i >= 70; i--) {
    repeat("u", 2);
    repeat("t", 1);
    repeat("0", 1);
    sety(19);
    repeat("l", 1);
  }
  repeat("u", 1);
  repeat("re", 31);
  for (int i = 100; i >= 70; i--) {
    repeat("u", 2);
    repeat("t", 1);
    repeat("1", 1);
    sety(20);
    repeat("l", 1);
  }
}
void addition() {
  for (int i = 100; i >= 70; i--) {
    setx(i), sety(18);
    repeat("dt0", 1);
    sety(17);
    repeat("e", 1);
    repeat("uutt0", 1);
    sety(18);
    repeat("dte", 1);
    sety(17);
    repeat("lrt0", 1);
    setx(i);
    repeat("e", 1);
    repeat("uuutt0", 1);
    sety(18);
    repeat("dte", 1);
    sety(17);
    repeat("lrt0", 1);
    setx(i);
    repeat("e", 1);
    repeat("ut0", 1);
    sety(18);
    repeat("dt1", 1);
  }
  setx(70), sety(18);
}
int main() {
  init(), copy(), addition();
  cout << ans << endl;
  return 0;
}
