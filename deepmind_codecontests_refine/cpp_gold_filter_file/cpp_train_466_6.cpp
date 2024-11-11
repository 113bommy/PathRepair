#include <bits/stdc++.h>
using namespace std;
int main() {
  int s[5], w[5], sh, wh;
  for (int i = 0; i < 5; i++) cin >> s[i];
  for (int i = 0; i < 5; i++) cin >> w[i];
  cin >> sh >> wh;
  int score = 0;
  for (int i = 0; i < 5; i++)
    score += max(30 * ((i + 1) * 500) / 100,
                 (250 - s[i]) * (((i + 1) * 500) / 250) - 50 * w[i]);
  score += sh * 100 - wh * 50;
  cout << score << '\n';
  return 0;
}
