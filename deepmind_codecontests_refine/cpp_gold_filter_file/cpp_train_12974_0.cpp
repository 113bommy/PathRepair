#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, counter = 0, sec, time = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> sec;
    time += 86400 - sec;
    counter++;
    if (time >= m) {
      cout << counter;
      return 0;
    }
  }
}
