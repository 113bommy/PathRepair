#include <bits/stdc++.h>
using namespace std;
int x, t;
int main() {
  for (int i = 1; i <= 5; i++) {
    scanf("%d", &x);
    t += x;
  }
  if (t % 5 == 0 && t) {
    cout << t / 5;
  } else
    cout << -1;
  return 0;
}
