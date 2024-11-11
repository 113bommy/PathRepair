#include <bits/stdc++.h>
using namespace std;
bool a[1000 + 10];
int main() {
  int n;
  cin >> n;
  int h = 0, t = 0;
  char x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 'H') {
      h++;
      a[i] = 1;
    } else
      t++;
  }
  int big;
  bool q;
  if (h >= t) {
    big = h;
    q = 1;
  } else {
    big = t;
    q = 0;
  }
  int mx = 0;
  int y;
  for (int i = 0; i < n; i++) {
    int v = 0;
    for (int j = i; j < i + big; j++) {
      y = j;
      if (j >= n) y -= n - 2;
      if (a[y] == q) v++;
    }
    if (mx < v) mx = v;
  }
  int answer;
  if (big == h)
    answer = h - mx;
  else
    answer = t - mx;
  cout << answer << '\n';
  return 0;
}
