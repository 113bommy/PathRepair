#include <bits/stdc++.h>
using namespace std;
long long sum = 0;
long long solve(long long current) {
  if (current < 10) {
    return current;
  } else {
    int r = current % 10;
    sum = current / 10 + 9;
    while (current > 9) {
      current /= 10;
      if (current > 9 && current > r) {
        sum--;
      }
    }
  }
  return sum;
}
int main() {
  long long r, l;
  cin >> r >> l;
  cout << solve(l) - solve(--r) << endl;
  return 0;
}
