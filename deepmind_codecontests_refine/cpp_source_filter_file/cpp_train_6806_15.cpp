#include <bits/stdc++.h>
using namespace std;
int s[2000000];
int n;
int sor = 0;
vector<int> cc;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", s + i);
  for (int i = 0; i < n; i++) sor |= s[i];
  int mm = 1;
  for (; mm <= sor; mm <<= 1)
    ;
  mm >>= 1;
  for (int i = 0; i < n; i++)
    if ((mm & s[i]) != 0) cc.push_back(i);
  while (cc.size() == n || cc.size() == 0) {
    cc.clear();
    mm >>= 1;
    for (int i = 0; i < n; i++)
      if ((mm & s[i]) != 0) cc.push_back(i);
  }
  int ii = 0;
  int imax = 0;
  int max2 = 0;
  for (int i = cc[0] - 1; i >= 0; i--) {
    max2 = max(s[i], max2);
    imax = max(imax, max2 ^ s[i]);
  }
  for (int i = 0; i < cc.size() - 1; i++) {
    max2 = 0;
    for (int j = cc[i] + 1; j <= cc[i + 1]; j++) {
      max2 = max(max2, s[j]);
      imax = max(imax, max2 ^ s[cc[i]]);
    }
    max2 = 0;
    for (int j = cc[i + 1] - 1; j > cc[i]; j--) {
      max2 = max(max2, s[j]);
      imax = max(imax, max2 ^ s[cc[i + 1]]);
    }
  }
  max2 = 0;
  for (int i = cc[cc.size() - 1] + 1; i < n; i++) {
    max2 = max(max2, s[i]);
    imax = max(imax, max2 ^ s[cc[cc.size() - 1]]);
  }
  printf("%d", imax);
}
