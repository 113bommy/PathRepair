#include <bits/stdc++.h>
using namespace std;
int main() {
  int K;
  cin >> K;
  int now = 0;
  for (int i = 0; i < 100000000; i++) {
    now = (now * 10 + 7) % K;
    if (now == 0) return cout << i << "\n", 0;
  }
  cout << -1 << "\n";
}
