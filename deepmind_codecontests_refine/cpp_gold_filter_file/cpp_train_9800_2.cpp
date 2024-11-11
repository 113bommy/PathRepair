#include <bits/stdc++.h>
using namespace std;
int mySearch(int u, int l, int s, int left);
int main() {
  while (true) {
    string s;
    cin >> s;
    if (!(s == "start")) break;
    int power = 1, lb = 0, ub = 0, counter = 0;
    for (int i = 0; i < 30; i++) {
      printf("? %d %d\n", (power * 2), power);
      fflush(stdout);
      string res;
      cin >> res;
      if (res == "x") {
        counter++;
        power *= 2;
        continue;
      }
      ub = 2 * power;
      lb = power;
      break;
    }
    if (counter == 30) {
      printf("! 1\n");
      fflush(stdout);
      continue;
    }
    if (power == 1) {
      printf("! 2\n");
      fflush(stdout);
      continue;
    }
    int ans = mySearch(ub, lb, power / 2, 60 - counter);
    if (ans == 0) break;
    printf("! %d\n", ans);
    fflush(stdout);
  }
}
int mySearch(int u, int l, int s, int left) {
  printf("? %d %d\n", l + s, l);
  fflush(stdout);
  string res;
  cin >> res;
  if (s == 0) return 0;
  if (left == 0)
    return 1;
  else if (res == "e")
    return 0;
  else if (s == 1) {
    int ret;
    ret = (res == "y") ? l + s : u;
    return ret;
  } else if (res == "x")
    return mySearch(u, l + s, s >> 1, left - 1);
  else
    return mySearch(l + s, l, s >> 1, left - 1);
  return 0;
}
