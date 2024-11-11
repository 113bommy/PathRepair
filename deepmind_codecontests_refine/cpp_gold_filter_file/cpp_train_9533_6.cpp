#include <bits/stdc++.h>
int i, maxx = 1, n;
char a[1000005];
std::vector<std::string> ans[1000005];
void go(int stage) {
  std::string think = "";
  int wtf = 0;
  while (a[i] != ',') {
    think += a[i];
    i++;
  }
  i++;
  ans[stage].push_back(think);
  while (a[i] != ',' && i < n) {
    wtf *= 10;
    wtf += a[i] - '0';
    i++;
  }
  i++;
  for (int i2 = 1; i2 <= wtf; i2++) {
    go(stage + 1);
  }
  if (stage > maxx) maxx = stage;
}
int main() {
  scanf("%s", a);
  i = 0;
  n = strlen(a);
  std::string think;
  int wtf;
  while (i < n) {
    think = "";
    wtf = 0;
    while (a[i] != ',') {
      think += a[i];
      i++;
    }
    i++;
    ans[1].push_back(think);
    while (a[i] != ',' && i < n) {
      wtf *= 10;
      wtf += a[i] - '0';
      i++;
    }
    i++;
    for (int i2 = 1; i2 <= wtf; i2++) {
      go(2);
    }
  }
  std::cout << maxx << std::endl;
  for (i = 1; i <= maxx; i++) {
    for (int i2 = 0; i2 < ans[i].size(); i2++) std::cout << ans[i][i2] << " ";
    std::cout << std::endl;
  }
  return 0;
}
