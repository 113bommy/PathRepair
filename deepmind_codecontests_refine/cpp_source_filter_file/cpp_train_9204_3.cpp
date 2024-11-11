#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  scanf("%d", &a);
  int sum = 0;
  vector<int> legit;
  int sum1 = 0;
  int sum2 = 0;
  for (int g = 0; g < a; g++) {
    int l;
    scanf("%d", &l);
    if (l % 2 == 0) {
      for (int g = 0; g < l; g++) {
        if (g < (l / 2)) {
          int u;
          scanf("%d", &u);
          sum1 += u;
        } else {
          int t;
          scanf("%d", &t);
          sum2 += t;
        }
      }
    } else {
      for (int g = 0; g < l; g++) {
        if (g < (l - 1) / 2) {
          int u;
          scanf("%d", &u);
          sum1 += u;
        } else if (g == (l - 1) / 2) {
          int u;
          scanf("%d", &u);
          legit.push_back(u);
        } else {
          int u;
          scanf("%d", &u);
          sum2 += u;
        }
      }
    }
  }
  sort(legit.begin(), legit.end());
  int l = legit.size() - 1 % 2;
  for (int g = legit.size() - 1; g >= 0; g--) {
    if (g % 2 == l) {
      sum1 += legit[g];
    } else {
      sum2 += legit[g];
    }
  }
  printf("%d", sum1);
  printf("%s", " ");
  printf("%d", sum2);
}
