#include <bits/stdc++.h>
using namespace std;
const long long INF = ~(1 << 31);
const double pi = acos(-1);
int main() {
  cin.sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  long long time = 0;
  long long start = 1;
  for (long long i = (0); i < (m); i++) {
    long long hold;
    cin >> hold;
    if (start <= hold)
      time += abs(start - hold);
    else {
      time += abs(start - n) + 1;
      start = 1;
      time += abs(start - hold);
    }
    start = hold;
  }
  cout << time << endl;
  return 0;
}
