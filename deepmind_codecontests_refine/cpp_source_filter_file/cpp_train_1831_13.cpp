#include <bits/stdc++.h>
using namespace std;
int n, v[5], p[5], solved[5];
int calc_score(int a, int b) {
  for (int i = 0; i < 5; i++) {
    int p = 1 << i;
    if ((a * p <= b) && (b < 2 * a * p)) {
      return (i + 1) * 500;
    }
  }
  return 3000;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 5; i++) {
    cin >> v[i];
    solved[i] += v[i] != -1;
  }
  for (int i = 0; i < 5; i++) {
    cin >> p[i];
    solved[i] += p[i] != -1;
  }
  for (int i = 2; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int x;
      cin >> x;
      if (x != -1) {
        solved[j]++;
      }
    }
  }
  int best = -1;
  for (int i = 0; i < 31 * n; i++) {
    int add[5] = {0};
    for (int j = 0; j < 5; j++) {
      if (v[j] != -1 && p[j] != -1 && v[j] > p[j]) {
        add[j] = i;
      }
    }
    int curr = 0;
    for (int j = 0; j < 5; j++) {
      int sc = calc_score(solved[j] + add[j], n + i);
      if (v[j] != -1) {
        curr += sc - v[j] * sc / 250;
      }
      if (p[j] != -1) {
        curr -= sc - p[j] * sc / 250;
      }
    }
    if (curr > 0) {
      best = i;
      break;
    }
  }
  cout << best << endl;
  return 0;
}
