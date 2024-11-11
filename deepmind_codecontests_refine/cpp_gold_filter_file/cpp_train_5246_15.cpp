#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string steps;
  cin >> n >> steps;
  int start;
  ;
  int finish;
  for (int i = 1; i < n; i++) {
    if (steps[i] != '.') {
      start = i + 1;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (steps[i - 1] == 'R' && steps[i] != 'R') {
      finish = i + 1;
      break;
    }
    if (steps[i - 1] == 'L' && steps[i] == '.') {
      finish = start - 1;
      break;
    }
  }
  cout << start << " " << finish;
}
