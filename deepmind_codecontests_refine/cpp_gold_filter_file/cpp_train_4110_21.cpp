#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m;
  long long v, t1, t2;
  cin >> m >> v >> t1 >> t2;
  long long sum1 = max(3 * m / 10, m - (m * t1) / 250);
  long long sum2 = max(3 * v / 10, v - (v * t2) / 250);
  if (sum1 > sum2) {
    cout << "Misha" << endl;
  } else if (sum1 == sum2) {
    cout << "Tie" << endl;
  } else {
    cout << "Vasya" << endl;
  }
}
