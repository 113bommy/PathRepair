#include <bits/stdc++.h>
using namespace std;
inline int getint() {
  int x;
  scanf("%d", &x);
  return x;
}
pair<int, int> temp[100000];
int nums[100000];
int answer[100000];
int n;
int a, b;
int main() {
  while (scanf("%d", &n) == 1) {
    scanf("%d %d", &a, &b);
    for (int i = 0, _n = (n); i < _n; ++i) nums[i] = getint();
    if (a < b) {
      for (int i = 0, _n = (n); i < _n; ++i) temp[i] = make_pair(-nums[i], i);
      sort(temp, temp + n);
      for (int i = 0, _n = (n); i < _n; ++i) answer[i] = 2;
      for (int i = 0, _n = (a); i < _n; ++i) answer[temp[i].second] = 1;
    } else if (a > b) {
      for (int i = 0, _n = (n); i < _n; ++i) temp[i] = make_pair(-nums[i], -i);
      sort(temp, temp + n);
      for (int i = 0, _n = (n); i < _n; ++i) answer[i] = 1;
      for (int i = 0, _n = (b); i < _n; ++i) answer[-temp[i].second] = 2;
    } else {
      for (int i = 0, _n = (n); i < _n; ++i) answer[i] = 2;
      for (int i = 0, _n = (a); i < _n; ++i) answer[i] = 1;
    }
    for (int i = 0, _n = (n); i < _n; ++i) {
      if (i) printf(" ");
      printf("%d", answer[i]);
    }
  }
  return 0;
}
