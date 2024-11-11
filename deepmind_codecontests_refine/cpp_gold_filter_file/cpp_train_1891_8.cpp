#include <bits/stdc++.h>
long long int gcd(unsigned long long int a, unsigned long long int b) {
  return (a == 0) ? b : gcd(b % a, a);
}
long long int lcm(unsigned long long int a, unsigned long long int b) {
  return a * (b / gcd(a, b));
}
int trinum(int x) { return x * (x + 1) / 2; }
int kx[8] = {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8] = {+1, -1, +1, -1, +2, -2, +2, -2};
using namespace std;
int main() {
  int X[6] = {4, 8, 15, 16, 23, 42};
  int x[6][6];
  int out[4];
  int n;
  pair<int, int> o[4];
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      x[i][j] = X[i] * X[j];
    }
  }
  for (int i = 1; i < 5; i++) {
    cout << "? 1 " << i + 1 << endl;
    fflush(stdout);
    cin >> out[i - 1];
  }
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        if (x[i][j] == out[k]) {
          o[k] = {i, j};
        }
      }
    }
  }
  if (o[0].first == o[1].first) {
    n = o[0].first;
  } else if (o[0].first == o[1].second) {
    n = o[0].first;
  } else if (o[0].second == o[1].first) {
    n = o[0].second;
  } else {
    n = o[0].second;
  }
  cout << "! " << X[n];
  map<int, bool> second;
  second[X[n]] = 1;
  for (int i = 0; i < 4; i++) {
    cout << ' ' << out[i] / X[n];
    second[out[i] / X[n]] = 1;
  }
  for (int i = 0; i < 6; i++) {
    if (!second[X[i]]) {
      if (X[i] != X[n]) {
        cout << ' ' << X[i];
      }
    }
  }
}
