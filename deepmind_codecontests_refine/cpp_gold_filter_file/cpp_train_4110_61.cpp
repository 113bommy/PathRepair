#include <bits/stdc++.h>
int score(int, int);
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int score_a = score(a, c);
  int score_b = score(b, d);
  if (score_a == score_b)
    cout << "Tie";
  else if (score_a > score_b)
    cout << "Misha";
  else
    cout << "Vasya";
  return 0;
}
int score(int p, int t) {
  int a1 = 3 * p / 10;
  int a2 = p - (p / 250) * t;
  if (a1 >= a2) return a1;
  return a2;
}
