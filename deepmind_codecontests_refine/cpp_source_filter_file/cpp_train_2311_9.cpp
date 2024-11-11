#include <bits/stdc++.h>
using namespace std;
double turns[100];
int links[100] = {0};
int to1d(int i, int j) { return i * 10 + (i % 2 ? 10 - j - 1 : j); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 10 - 1; i >= 0; i--) {
    for (int j = 0; j < 10; j++) {
      int a;
      cin >> a;
      links[to1d(i, j)] = to1d(i + a, j);
    }
  }
  for (int i = 100 - 1; i >= 0; i--) {
    if (i + 6 >= 100 - 1) {
      turns[i] = 6;
      continue;
    }
    double sum = 0;
    for (int j = 1; j <= 6; j++) {
      sum += min(turns[i + j], turns[links[i + j]]) + 1;
    }
    turns[i] = sum / 6;
  }
  printf("%.10f", turns[0]);
}
