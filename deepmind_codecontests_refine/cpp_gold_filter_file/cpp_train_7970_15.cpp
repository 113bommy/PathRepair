#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, prob, time;
  cin >> prob >> time;
  time = 240 - time;
  for (i = 0; i <= prob; i++) {
    if ((5 * i * (i + 1)) / 2 > time) {
      break;
    }
  }
  cout << i - 1 << endl;
}
