#include <bits/stdc++.h>
using namespace std;
int main() {
  int D;
  cin >> D;
  for (int i = 10; i < D+10; i++) {
    cout << i % 26 + 1 << endl;
  }
  return 0;
}
