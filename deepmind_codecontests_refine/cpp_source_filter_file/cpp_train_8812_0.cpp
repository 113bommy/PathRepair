#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.setf(ios::fixed, ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(12);
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  long long n, k, M, D;
  cin >> n >> k >> M >> D;
  long long best = M;
  for (int cycles = 1; cycles < D; ++cycles) {
    long long num_people = cycles * k + 1;
    long long x = n / num_people;
    if (x == 0) break;
    if (x > M) continue;
    best = max(best, (cycles + 1) * x);
  }
  cout << best << endl;
  return 0;
}
