#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;
int main() {
  int n, time = 0, mintime = 10000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < a[i]; x++) {
      int p;
      cin >> p;
      time = time + (p * 5);
    }
    time = time + (a[i] * 15);
    if (time < mintime) {
      mintime = time;
    }
    time = 0;
  }
  cout << mintime;
}
