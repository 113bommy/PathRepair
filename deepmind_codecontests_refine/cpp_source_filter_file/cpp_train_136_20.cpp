#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
  cin >> a >> b >> c;
  int best = 0;
  for (int i = 0; i < 10000; i++) {
    int end = i + c;
    if (end * b >= a * c) {
      best = i;
      break;
    }
  }
  cout << best << endl;
}
