#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  vector<int> points;
  vector<int> times;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    points.push_back(x);
  }
  for (int j = 0; j < n; j++) {
    int y;
    cin >> y;
    times.push_back(y);
  }
  int tl = 0;
  int l = 0;
  int r = 0;
  int tr = 0;
  for (int k = 0; k < n; k++) {
    tl += times[k];
    int score = points[k] - c * tl;
    l += (score > 0 ? score : 0);
  }
  for (int m = n - 1; m <= 0; m--) {
    tr += times[m];
    int score2 = points[m] - c * tr;
    r += (score2 > 0 ? score2 : 0);
  }
  if (l > r) {
    cout << "Limak";
  } else if (r > l) {
    cout << "Radewoosh";
  } else {
    cout << "Tie";
  }
}
