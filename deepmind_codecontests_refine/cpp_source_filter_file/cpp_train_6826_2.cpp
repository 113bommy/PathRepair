#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int maxScore = 0;
  string maxName = "";
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    int p, m, a, b, c, d, e;
    cin >> p >> m >> a >> b >> c >> d >> e;
    int score = p * 100 - m * 50 + a + b + c + d + e;
    if (score > maxScore) {
      maxScore = score;
      maxName = name;
    }
  }
  cout << maxName;
}
