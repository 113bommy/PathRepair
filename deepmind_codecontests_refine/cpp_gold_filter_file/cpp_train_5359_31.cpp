#include <bits/stdc++.h>
using namespace std;
bool allhappy(int boy[], int girl[], int n, int m) {
  bool happy = true;
  for (int i = 0; i < n; i++) happy = boy[i] && happy;
  for (int i = 0; i < m; i++) happy = girl[i] && happy;
  return happy;
}
int main() {
  int n, m;
  cin >> n >> m;
  int b, g;
  int boy[101] = {0}, girl[101] = {0};
  int occupied[101][101] = {0};
  int temp;
  cin >> b;
  for (int i = 0; i < b; i++) {
    cin >> temp;
    boy[temp]++;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    cin >> temp;
    girl[temp]++;
  }
  int i = 0;
  while (!allhappy(boy, girl, n, m)) {
    boy[i % n] = girl[i % m] = boy[i % n] || girl[i % m];
    if (i > n * m + m + n) {
      cout << "NO" << endl;
      return 0;
    }
    i++;
  }
  if (allhappy(boy, girl, n, m))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
