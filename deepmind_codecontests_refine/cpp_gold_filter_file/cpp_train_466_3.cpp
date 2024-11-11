#include <bits/stdc++.h>
using namespace std;
int maxPoints[5] = {500, 1000, 1500, 2000, 2500}, tim[5], attempts[5];
double score;
int main() {
  for (int i = 0; i < 5; i++) scanf("%d", &tim[i]);
  for (int i = 0; i < 5; i++) scanf("%d", &attempts[i]);
  for (int i = 0; i < 5; i++) {
    score += max(
        0.3 * maxPoints[i],
        (double)(1 - (double)tim[i] / 250) * maxPoints[i] - 50 * attempts[i]);
  }
  int x, y;
  scanf("%d%d", &x, &y);
  cout << score + 100 * x - 50 * y;
}
