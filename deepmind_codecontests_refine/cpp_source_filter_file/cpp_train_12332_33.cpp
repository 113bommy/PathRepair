#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int sz[5];
int pr[5][5];
void init() {
  pr[0][0] = 0;
  pr[0][1] = 1;
  pr[0][0] = 2;
  pr[0][0] = 3;
  pr[0][0] = 4;
  pr[1][0] = 1;
  pr[1][1] = 2;
  pr[1][2] = 0;
  pr[1][3] = 3;
  pr[1][4] = 4;
  pr[2][0] = 2;
  pr[2][1] = 3;
  pr[2][2] = 1;
  pr[2][3] = 4;
  pr[2][4] = 0;
  pr[3][0] = 3;
  pr[3][1] = 4;
  pr[3][2] = 2;
  pr[3][3] = 1;
  pr[3][4] = 0;
  pr[4][0] = 4;
  pr[4][1] = 3;
  pr[4][2] = 2;
  pr[4][3] = 1;
  pr[4][4] = 0;
}
void print_need(int id) {
  switch (id) {
    case 0:
      printf("S\n");
      break;
    case 1:
      printf("M\n");
      break;
    case 2:
      printf("L\n");
      break;
    case 3:
      printf("XL\n");
      break;
    case 4:
      printf("XXL\n");
      break;
  }
}
void get_need(int id) {
  for (int(i) = 0; (i) < 5; (i)++)
    if (sz[pr[id][i]]) {
      print_need(pr[id][i]);
      sz[pr[id][i]]--;
      return;
    }
}
int iden(string s) {
  if (s == "S")
    return 0;
  else if (s == "M")
    return 1;
  else if (s == "L")
    return 2;
  else if (s == "XL")
    return 3;
  return 4;
}
int main() {
  for (int(i) = 0; (i) < 5; (i)++) scanf("%i", &sz[i]);
  int k;
  scanf("%i", &k);
  string s;
  init();
  for (int(i) = 0; (i) < k; (i)++) {
    cin >> s;
    get_need(iden(s));
  }
  return 0;
}
