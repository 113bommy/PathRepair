#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s;
  for (int i = 0; i <= 8; i++) printf("%d??<>%d\n", i, i + 1);
  printf("9??>>??0\n");
  printf("??0<>10\n");
  for (int i = 0; i <= 9; i++) printf("?%d>>%d?\n", i, i);
  printf("?>>??\n");
  printf(">>?");
}
