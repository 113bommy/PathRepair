#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int t1, t2, p1, p2;
  cin >> t1 >> t2 >> p1 >> p2;
  if ((t1 == 0 && p1 == N) || (t1 == N && p1 == 0))
    cout << min(t2 + N + p2, N - t2 + N + N - p2) << endl;
  else if ((t2 == 0 && p2 == N) || (t2 == N && p2 == 0))
    cout << min(t1 + N + p1, N - t1 + N + N - p1) << endl;
  else
    cout << abs(p1 - t1) + abs(p2 - t2) << endl;
  return 0;
}
