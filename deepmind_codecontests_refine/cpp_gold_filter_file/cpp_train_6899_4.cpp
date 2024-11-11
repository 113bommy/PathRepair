#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
clock_t timeStart, timeFinish;
void timeBegin() { timeStart = clock(); }
void timeEnd() { timeFinish = clock(); }
void timeDuration() {
  double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
  cout << "Time taken by program is : " << fixed << time_taken
       << setprecision(5);
  cout << " sec " << endl;
}
void solve() {
  string s;
  cin >> s;
  int n = s.length();
  cout << "3\nL " << n - 1 << '\n';
  cout << "R " << n - 1 << '\n';
  cout << "R " << 2 * n - 1 << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
