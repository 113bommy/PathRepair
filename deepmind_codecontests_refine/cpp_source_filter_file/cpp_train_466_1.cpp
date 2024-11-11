#include <bits/stdc++.h>
using namespace std;
int main() {
  int m[5], w[5], h[2];
  int i;
  for (i = 0; i < 5; i++) cin >> m[i];
  for (i = 0; i < 5; i++) cin >> w[i];
  cin >> h[0] >> h[1];
  double score = 0.0;
  const int X = 500;
  for (i = 0; i < 5; i++) {
    int x = X * (i + 1);
    score += max(0.3 * x, (1 - (m[i] / 250.0)) * x - (50.0 * w[i]));
  }
  score += h[0] * 100 - h[1] * 50;
  cout << (int)score << endl;
  return 0;
}
