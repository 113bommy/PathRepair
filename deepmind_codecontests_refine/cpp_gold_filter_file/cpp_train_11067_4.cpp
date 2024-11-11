#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long a, b;
  cin >> a >> b;
  long long x1 = 0, y1 = 1000;
  for (int i = 0; i < a; i++) {
    long long t1, t2;
    cin >> t1 >> t2;
    x1 = max(x1, min(t1, t2));
    y1 = min(max(t2, t1), y1);
  }
  if (x1 > y1) {
    cout << -1;
    exit(0);
  }
  if (x1 <= b && y1 >= b) {
    cout << 0;
    exit(0);
  }
  cout << min(abs(x1 - b), abs(b - y1));
  return 0;
}
