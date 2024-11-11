#include <bits/stdc++.h>
using namespace std;
const int N = 101111;
int a[N], ANS = 0, n;
vector<int> ans[N], tmp, tmp2, tmp3;
bool vis[N];
void go() {
  if (tmp.size() == 1) return;
  int p = tmp[0];
  int siz = tmp.size() - 1, i;
  for (i = 1; i + 3 <= siz; i += 4) {
    ANS++;
    ans[ANS].push_back(p);
    for (int j = (i); j <= (i + 3); j++) ans[ANS].push_back(tmp[j]);
  }
  if (i == siz) {
    tmp2.push_back(tmp[siz]);
    tmp2.push_back(p);
  } else if (i + 1 == siz) {
    tmp3.push_back(tmp[i + 1]);
    tmp3.push_back(tmp[i]);
    tmp3.push_back(p);
  } else if (i + 2 == siz) {
    ANS++;
    ans[ANS].push_back(p);
    for (int j = (i); j <= (i + 2); j++) ans[ANS].push_back(tmp[j]);
  }
}
void print() {
  for (int j = (1); j <= (ANS); j++) {
    int siz = ans[j].size();
    printf("%d\n", siz);
    for (int i = (0); i <= (siz - 1); i++) printf("%d ", ans[j][i]);
    printf("\n");
    for (int i = (1); i <= (siz - 1); i++) printf("%d ", ans[j][i]);
    printf("%d\n", ans[j][0]);
  }
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n); i++) scanf("%d", a + i);
  for (int i = (1); i <= (n); i++) {
    if (vis[i]) continue;
    tmp.clear();
    int p = i;
    while (!vis[p]) {
      vis[p] = 1;
      tmp.push_back(p);
      p = a[p];
    }
    go();
  }
  int num2 = tmp2.size() / 2, num3 = tmp3.size() / 3;
  int pp[6];
  while (num2 < num3) {
    for (int i = (1); i <= (3); i++) {
      pp[i] = tmp3.back();
      tmp3.pop_back();
    }
    if (num2 + 1 == num3) {
      ANS++;
      for (int i = (1); i <= (3); i++) ans[ANS].push_back(pp[i]);
      num3--;
      break;
    }
    num2 += 2;
    num3--;
    tmp2.push_back(pp[3]);
    tmp2.push_back(pp[1]);
    tmp2.push_back(pp[2]);
    tmp2.push_back(pp[1]);
  }
  if (1 || num2 >= num3) {
    printf("%d\n", ANS + (num2 + num3 + 1) / 2);
    print();
    for (int j = (1); j <= (num3); j++) {
      printf("5\n");
      for (int i = (1); i <= (3); i++) {
        pp[i] = tmp3.back();
        tmp3.pop_back();
      }
      for (int i = (4); i <= (5); i++) {
        pp[i] = tmp2.back();
        tmp2.pop_back();
      }
      for (int i = (1); i <= (5); i++) printf("%d ", pp[i]);
      printf("\n");
      for (int i = (2); i <= (3); i++) printf("%d ", pp[i]);
      printf("%d %d %d\n", pp[1], pp[5], pp[4]);
    }
    for (int j = (1); j <= ((num2 - num3) / 2); j++) {
      printf("4\n");
      for (int i = (1); i <= (4); i++) {
        pp[i] = tmp2.back();
        tmp2.pop_back();
        printf("%d ", pp[i]);
      }
      printf("\n");
      printf("%d %d %d %d\n", pp[2], pp[1], pp[4], pp[3]);
    }
    if ((num2 - num3) % 2) {
      printf("2\n");
      for (int i = (1); i <= (2); i++) {
        pp[i] = tmp2.back();
        tmp2.pop_back();
        printf("%d ", pp[i]);
      }
      printf("\n");
      printf("%d %d\n", pp[2], pp[1]);
    }
  }
  return 0;
}
