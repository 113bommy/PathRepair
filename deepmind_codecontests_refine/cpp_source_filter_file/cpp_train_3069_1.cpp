#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0;
  map<char, int> weight = {
      {'q', 9},  {'r', 5},  {'b', 3},  {'n', 3},  {'p', 1},  {'k', 0}, {'.', 0},
      {'Q', -9}, {'R', -5}, {'B', -3}, {'N', -3}, {'P', -1}, {'K', -0}};
  char a[8][8];
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) cin >> a[i][j];
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j) sum += weight[a[i][j]];
  if (sum > 0)
    cout << "White";
  else if (sum < 0)
    cout << "Black";
  else
    cout << "Draw";
}
