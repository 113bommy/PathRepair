#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  stack<int> s;
  for (int i = 1; i <= 11; i++) {
    int x;
    cin >> x;
    s.push(x);
  }
  float p = 0;
  for (int i = 11; i >= 1; i--) {
    int x = s.top();
    s.pop();
    float a = sqrt(abs(x));
    int b = x * x * x * 5;
    float res = a + b;
    if (res > 400)
      printf("f(%d) = MAGNA NIMIS!\n", x);
    else
      printf("f(%d) = %.2f\n", x, res);
  }
  return 0;
}
