#include <bits/stdc++.h>
using namespace std;
int sum = 0, s[510];
void bigy(int y) {
  int i = 0;
  while (9 - s[i] < y - sum) {
    sum = sum - s[i] + 9;
    s[i] = 9;
    i++;
  }
  s[i] += y - sum;
  sum = y;
}
void smally(int y) {
  int i = 0;
  while (sum > y) {
    sum -= s[i];
    s[i] = 0;
    i++;
    while (s[i] == 9) {
      sum -= 9;
      s[i] = 0;
      i++;
    }
    sum++;
    s[i]++;
  }
  if (sum < y) bigy(y);
}
void work(int y) {
  int i = 0;
  i = 0;
  while (s[i] == 9) {
    sum -= 9;
    s[i] = 0;
    i++;
  }
  sum++;
  s[i]++;
  if (sum < y)
    bigy(y);
  else if (sum > y)
    smally(y);
  bool ot = false;
  for (i = 500; i >= 0; i--) {
    if (ot || s[i] > 0) {
      printf("%d", s[i]);
      if (!ot) ot = true;
    }
  }
  cout << endl;
}
int main() {
  int n, now;
  memset(s, 0, sizeof(s));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> now;
    work(now);
  }
  return 0;
}
