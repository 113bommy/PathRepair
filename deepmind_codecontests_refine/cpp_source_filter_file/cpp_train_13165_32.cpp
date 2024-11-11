#include <bits/stdc++.h>
using namespace std;
int main() {
#pragma warning(disable : 4996)
  int ar[10] = {2, 7, 2, 3, 3, 2, 2, 5, 1, 2};
  vector<int> v;
  char c;
  while (scanf(" %c", &c) > 0 && c != '\n') {
    v.push_back(c -= '0');
  }
  int ans = 1;
  for (int i = 0; i < v.size(); i++) ans *= ar[v[i]];
  printf("%d", ans);
  return 0;
}
