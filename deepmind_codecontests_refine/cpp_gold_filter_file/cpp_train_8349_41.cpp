#include <bits/stdc++.h>
using namespace std;
int minutes(int);
int main() {
  int t, l;
  cin >> t;
  l = minutes(t);
  return 0;
}
int minutes(int t) {
  int h = 0, m = 0;
  for (int i = 1; i <= t; i++) {
    cin >> h >> m;
    int hours, min;
    hours = (24 - h) * 60;
    min = 0 - m;
    cout << hours + min << "\n";
  }
  return 0;
}
