#include <bits/stdc++.h>
using namespace std;
int n, k;
int solve(int v) {
  int sum = 0;
  int powerOfK = 1;
  for (int i = 0;; i++) {
    int val = v / powerOfK;
    powerOfK *= k;
    if (val == 0) return sum;
    sum += val;
  }
}
int main() {
  cin >> n >> k;
  int st = 0, en = 1e9;
  while (st != en) {
    int mid = (st + en) / 2;
    int sol = solve(mid);
    if (sol < n)
      st = mid + 1;
    else
      en = mid;
  }
  cout << st;
}
