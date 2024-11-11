#include <bits/stdc++.h>
using namespace std;
void loadData(void);
void proc(void);
void printRes(void);
int a, b, mod;
string winner;
int one_choose;
int main(int argc, char** argv) {
  loadData();
  proc();
  printRes();
  return 0;
}
void proc(void) {
  int res;
  winner = "2";
  for (res = 0; res <= min(a, mod); res++) {
    int amod = (int)((long long)((((long long)res) * ((long long)1000000000)) %
                                 ((long long)mod)));
    if ((mod - amod) % mod > b) {
      winner = "1";
      one_choose = res;
      break;
    }
  }
  return;
}
void loadData(void) {
  scanf("%d%d%d", &a, &b, &mod);
  return;
}
void printRes(void) {
  if (winner == "1") {
    printf("%s\n%09d\n", winner.c_str(), one_choose);
  } else
    printf("2\n");
  return;
}
