#include <bits/stdc++.h>
using namespace std;
int n;
int x[1001];
int y[1001];
int countX;
int main(int argc, char** argv) {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> x[i];
    cin >> y[i];
  }
  countX = 0;
  for (int i = 1; i < n; i++) {
    if ((x[i - 1] < x[i] && y[i] < y[i + 1]) ||
        (y[i - 1] > y[i] && x[i] < x[i + 1]) ||
        (x[i - 1] > x[i] && y[i] > y[i + 1]) ||
        (y[i - 1] < y[i] && x[i] > x[i + 1]))
      countX++;
  }
  cout << countX;
}
