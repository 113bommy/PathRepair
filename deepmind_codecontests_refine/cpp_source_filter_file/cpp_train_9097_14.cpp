#include <bits/stdc++.h>
using namespace std;
int solve(long long k) {
  if (k < 3) {
    return 1;
  }
  if (k % 3 == 0) {
    return solve(k / 3);
  } else {
    return (k + 2) / 3;
  }
}
int main(int argc, char *argv[]) {
  long long n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
