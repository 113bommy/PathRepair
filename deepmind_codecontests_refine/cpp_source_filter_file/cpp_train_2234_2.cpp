#include <bits/stdc++.h>
using namespace std;
int main() {
  int limit, multiple_of;
  cin >> limit >> multiple_of;
  int steps = -1;
  int reqsteps = limit / 2 + limit % 2;
  for (int i = reqsteps; i < limit; i++) {
    if (i % multiple_of == 0) {
      steps = i;
      break;
    }
  }
  cout << steps;
  return 0;
}
